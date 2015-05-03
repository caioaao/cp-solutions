#include <bits/stdc++.h>

#define MAX_PR 10001

using namespace std;

typedef long long LL;

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
	Edge &e = G[x][i];
	if (!dad[e.to] && e.cap - e.flow > 0) {
	  dad[e.to] = &G[x][i];
	  Q[tail++] = e.to;
	}
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	if (!e) { amt = 0; break; }
	amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	e->flow += amt;
	G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};
typedef vector<int> vi;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b);}

vi vA;
map<int,int> gL, gR;
int t, n;

vi primes;
bitset<MAX_PR> isP;

inline int getPf(int x){
  int ret = 1;
  for(int i = 0; i < primes.size() && x > 1; i++){
    if(x % primes[i] == 0){
      ret *= primes[i];
      while(x % primes[i] == 0) x /= primes[i];
    }
  }
  return ret;
}

inline void markP(int x){
  primes.push_back(x);
  for(int i = x+x; i < MAX_PR; i+=x) isP.reset(i);
}

void sieve(){
  isP.set();
  markP(2);
  for(int i = 3; i < MAX_PR; i+=2){
    if(isP[i]) markP(i);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  sieve();
  cin >> t;
  while(t--){
    cin >> n;
    gL.clear(); gR.clear();
    vA.clear();
    int x;
    for(int i = 0; i < n; i++){
      cin >> x;
      vA.push_back(x);
    }
    int g;
    for(int j = 0; j < n; j++){
      cin >> x;
      
      for(int i = 0; i < n; i++){
        if(vA[i] < x){ // Left
          g = getPf(gcd(vA[i],x));
          if(g > 1){
            if(!gL.count(g)){
              gL[g] = 0;
            }
            gL[g]++;
          }
        }
        else if(vA[i] > x){ // Right
          g = getPf(gcd(vA[i],x));
          if(g > 1){
            if(!gR.count(g)){
              gR[g] = 0;
            }
            gR[g]++;
          }
        }
      }
    }
    
    int source = 0, target = gL.size()+gR.size() + 1;
    
    Dinic df(gL.size() + gR.size() + 2);
    map<int,int>::const_iterator it, it2;
    int id, id2;
    for(it = gL.begin(), id = 1; it != gL.end(); ++it, id++){
      df.AddEdge(source, id, it->second);
    }
    for(it = gR.begin(), id = gL.size()+1;it != gR.end(); ++it, id++){
      df.AddEdge(id, target, it->second);
    }
    
    for(it = gL.begin(), id = 1; it != gL.end(); ++it, id++){
      for(it2 = gR.begin(), id2 = gL.size()+1;it2 != gR.end(); ++it2, id2++){
        if(gcd(it->first, it2->first) > 1){
          df.AddEdge(id,id2, it->second);
        }
      }
    }
    
    cout << df.GetMaxFlow(source, target) << '\n';
    
  }
}
