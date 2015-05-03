#include <bits/stdc++.h>

#define INF 0x7ffff

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

struct point{
  int x, y;
};

typedef vector<point> vp;

const int MAXN1 = 10000; //Maximo de vertices do conj. 1
const int MAXN2 = 10000; //Maximo de vertices do conj. 2
const int MAXM = 100000; //Maximo de Edges

int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prev[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prev[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || ((!vis[u2] && dist[u2] == dist[u1] + 1) && dfs(u2))) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
inline int dist2(point p, point q){ return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y); }

int P, k, nr, nb;

vp reds, blues;

int flow2(int d){
    init(nr,nb);
    
    for(int i = 0; i < nr; i++){
      for(int j = 0; j < nb; j++){
        if(dist2(reds[i],blues[j]) <= d)
          addEdge(i, j);
      }
    }
    return maxMatching();
}

int bs(int hi){
  int lo = 0, mi;
  while(lo +1 < hi){
    mi = (hi + lo)/2;
    if(flow2(mi*mi) < k){
      lo = mi;
    }
    else{
      hi = mi;
    }
  }
  if(flow2(lo*lo) >= k) return lo;
  else if(flow2(hi*hi) >= k) return hi;
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while(t--){
    cin >> P >> k;
    reds.clear();
    blues.clear();
    string cor;
    point pole;
    for(int i = 0; i < P; i++){
      cin >> pole.x >> pole.y >> cor;
      if(cor[0] == 'r') reds.push_back(pole);
      else blues.push_back(pole);
    }
    
    nr = reds.size(); nb = blues.size();
    int max_d = 0;
    for(int i = 1; i <= nr; i++){
      for(int j = 1; j <= nb; j++){
        max_d = max(max_d,(int)sqrt(dist2(reds[i-1],blues[j-1])) + 1);
      }
    }
    
    int ans = bs(max_d);
    if(ans != -1) cout << ans << '\n';
    else cout << "Impossible\n";
  }
}
