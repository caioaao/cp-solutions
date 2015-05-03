#include <bits/stdc++.h>

#define MAX_N 100010
#define LOG_TWO_N 18
#define INF 1e9

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vvi AdjList, children;
vi visited;

int n, m1, m2;
int L[2*MAX_N], E[2*MAX_N], H[MAX_N], idx, SpT[2*MAX_N][LOG_TWO_N];

void buildSparseTable() {
  for (int i = 0; i < 2*n; i++)
    SpT[i][0] = i; 
    
  for (int j = 1; (1<<j) <= 2*n; j++) 
    for (int i = 0; i + (1<<j) - 1 < 2*n; i++)    
      if (L[SpT[i][j-1]] < L[SpT[i+(1<<(j-1))][j-1]])            
        SpT[i][j] = SpT[i][j-1];    
      else                 
        SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
}

int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    if (L[SpT[i][k]] <= L[SpT[j-(1<<k)+1][k]])
      return SpT[i][k];
    else
      return SpT[j-(1<<k)+1][k];
}

void dfsLCA(int cur, int depth){
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for(int i = 0; i < (int)children[cur].size(); i++){
    dfsLCA(children[cur][i], depth+1);
    E[idx] = cur;
    L[idx++] = depth;
  }
}

void dfsRoot(int u){
  visited[u] = 1;
  for(int i = 0; i < (int)AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(!visited[v]){
      children[u].push_back(v);
      dfsRoot(v);
    }
  }
}

void buildLCA(){
  // root tree
  children.assign(n,vi());
  visited.assign(n,0);
  dfsRoot(0);

  // build Sparse Table
  idx = 0;

  memset(H,-1,sizeof H);

  dfsLCA(0,0);

  buildSparseTable();
}

vii ps1, ps2;
vi ls1, ls2;

inline bool between(int x, int s, int t){
  if(L[H[x]] < L[H[s]]) return false;
  if(L[H[x]] > L[H[t]]) return false;
  
  if(H[x] < H[s]) return false;
  if(H[x] > H[t]) return false;
  
  return E[query(H[x],H[t])] == x && E[query(H[s], H[x])] == s;
}

inline bool intersects(int u1, int v1, int l1, int u2, int v2, int l2){
  return between(l1,l2,u2) ||
          between(l1,l2,v2) ||
          between(l2,l1,u1) ||
          between(l2,l1,v1);
}

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<int> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], int(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  int GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    int totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n >> m1 >> m2;
  int u, v;
  AdjList.assign(n,vi());
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    u--; v--;
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
  }
  
  buildLCA();

  ps1.assign(m1,ii());
  ps2.assign(m2,ii());
  ls1.assign(m1,0);
  ls2.assign(m2,0);
  
  int amtT = 0, joy;
  PushRelabel pr(m1+m2+2);
  
  for(int i = 0; i < m1; i++){
    cin >> ps1[i].first >> ps1[i].second >> joy;
    amtT += joy;
    ps1[i].first--; ps1[i].second--;
    if(H[ps1[i].first] > H[ps1[i].second])
      swap(ps1[i].first, ps1[i].second);
    ls1[i] = E[query(H[ps1[i].first],H[ps1[i].second])];
    pr.AddEdge(0,i+1,joy);
  }
  
  for(int i = 0; i < m2; i++){
    cin >> ps2[i].first >> ps2[i].second >> joy;
    amtT += joy;
    ps2[i].first--; ps2[i].second--;
    if(H[ps2[i].first] > H[ps2[i].second])
      swap(ps2[i].first, ps2[i].second);
    ls2[i] = E[query(H[ps2[i].first],H[ps2[i].second])];
    pr.AddEdge(i+1+m1, m1+m2+1, joy);
  }
  
  for(int i = 0; i < m1; i++){
    for(int j = 0; j < m2; j++){
      if(intersects(ps1[i].first, ps1[i].second, ls1[i], ps2[j].first, ps2[j].second, ls2[j])){
        pr.AddEdge(i+1,j+1+m1,INF);
      }
    }
  }
  
  cout << amtT - pr.GetMaxFlow(0,m1+m2+1) << '\n';
}
