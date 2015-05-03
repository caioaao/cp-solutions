#include <bits/stdc++.h>

#define pb push_back
#define sz size

#define ff first
#define ss second

#define UNK -1
#define EXPL 0
#define VIS 1

#define INF 1e9

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;

int S, T;


vvii AdjList;

////////////////////////////////////////////////////////////////////////
// DIJKSTRA
////////////////////////////////////////////////////////////////////////

vi visited, dist;
priority_queue<ii, vector<ii>, greater<ii> > pq;
void diks(int beg){
  dist.assign(S, INF);
  dist[beg] = 0;
  pq.push(ii(0,beg));
  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    ll d = front.ff, u = front.ss;
    if(d > dist[u]) continue;
    for(int j = 0; j < (int) AdjList[u].sz(); j++){
      ii v = AdjList[u][j];
      if(dist[u] + v.ss < dist[v.ff]){
        dist[v.ff] = dist[u] + v.ss;
        pq.push(ii(dist[v.ff], v.ff));
      }
    }
  }
}
////////////////////////////////////////////////////////////////////////
// END DIJKSTRA
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
// CYCLE-FINDING
////////////////////////////////////////////////////////////////////////
vi sccIds, states, expl_id, sccSz;
vii exploring;

int sccId;

void dfs(int u, int p,  int lc){
  states[u] = EXPL;
  expl_id[u] = exploring.sz();
  exploring.pb(ii(u,lc));
  
  for(int j = 0; j < (int) AdjList[u].sz(); j++){
    ii v = AdjList[u][j];
    if(v.ff != p){
      if(states[v.ff] == UNK){
        dfs(v.ff, u, v.ss);
      }
      else if(states[v.ff] == EXPL){
        // V eh root do ciclo, logo o custo de entrada em V é exterior
        // ao ciclo
        sccSz[sccId] = v.ss;
        
        int i = expl_id[u];
        while(1){
          sccIds[exploring[i].ff] = sccId;
          if(i == expl_id[v.ff]) break;
          sccSz[sccId] += exploring[i--].ss;
        }
        sccId++;
      }
    }
  }
  
  exploring.pop_back();
  states[u] = VIS;
}
////////////////////////////////////////////////////////////////////////
// END CYCLE-FINDING
////////////////////////////////////////////////////////////////////////


// CASO ESPECIAL: ciclo de 2 vértices
map<ii, ll> edges;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  while(cin >> S >> T){
    AdjList.assign(S,vii());
    sccIds.assign(S,-1);
    states.assign(S,UNK);
    sccId = 0;
    edges.clear();
    int a,b;
    ll w;
    ii E;
    while(T--){
      cin >> a >> b >> w;
      a--; b--;
      if(a > b) swap(a,b);
      E = ii(a,b);
      if(edges.count(E)){
        states[a] = states[b] = VIS;
        sccIds[a] = sccIds[b] = sccId;
        sccSz[sccId] = w + edges[E];
        sccId++;
      }
      else{
        edges[E] = w;
        AdjList[a].pb(ii(b,w));
        AdjList[b].pb(ii(a,w));
      }
    }
    exploring.clear();
    expl_id.assign(S,-1);
    sccSz.assign(S,0);
    for(int i = 0; i < S; i++) if(states[i] == UNK)
      dfs(i, -1, 0);
    sccSz.resize(sccId);
      
    int Q;
    ll M, X;
    cin >> Q;
    while(Q--){
      cin >> X >> M;
      X--;
      
      diks(X);
      ll bst = INF;
      for(int u = 0; u < S; u++)if(sccIds[u] != -1 && sccSz[sccIds[u]] >= M){
        bst = min(bst, dist[u] * 2 + sccSz[sccIds[u]]);
      }
      cout << (bst < INF ? bst : -1) << '\n';
    }
  }
}
