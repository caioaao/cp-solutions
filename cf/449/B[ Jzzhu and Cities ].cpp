#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

typedef long long ll;

struct edge{
  ll w;
  int v,t;
  
  edge():
    w(0), v(0), t(0){ }
  
  edge(int _v, ll _w, int _t):
  w(_w), v(_v), t(_t){ }
};

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<edge> ve;
typedef vector<ve> vve;

vector<int> indeg;
int n, m, k;

vve AdjList, AdjList2;
vector<ll> dist;

priority_queue<ii, vector<ii>, greater<ii> > pq;

void dsk(){
  dist.assign(n,INF);
  dist[0] = 0;
  pq.push(ii(0,0));
  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    ll d = front.first, u = front.second;
    if(d > dist[u]) continue;
    for(int j = 0; j < (int)AdjList[u].size(); j++){
      edge e = AdjList[u][j];
      if(dist[u] + e.w < dist[e.v]){
        dist[e.v] = dist[u] + e.w;
        pq.push(ii(dist[e.v],e.v));
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  while(cin >> n >> m >> k){
    AdjList.assign(n,ve());
    
    ll a, b, w;
    for(int i = 0; i < m; i++){
      cin >> a >> b >> w;
      
      a--; b--;
      
      AdjList[a].push_back(edge(b,w,0));
      AdjList[b].push_back(edge(a,w,0));
      
    }
    
    for(int i = 0; i < k; i++){
      cin >> b >> w;
      b--;
      AdjList[0].push_back(edge(b,w,1));
    }
    
    dsk();
    
    AdjList2.assign(n,ve());
    indeg.assign(n,0);
    
    int ans = 0;
    for(int u = 0; u < n; u++){
      for(int j = 0; j < (int)AdjList[u].size(); j++){
        edge e = AdjList[u][j];
        if(dist[u] + e.w == dist[e.v]){
          indeg[e.v]++;
          AdjList2[u].push_back(e);
        }
        else if(e.t == 1){
          ans++;
        }
      }
    }
    
    for(int j = 0; j < (int)AdjList2[0].size(); j++){
      edge e = AdjList2[0][j];
      if(indeg[e.v] > 1 && e.t == 1){
        indeg[e.v]--;
        ans++;
        //~ cout << v << endl;
      }
    }
    //~ cout << "ans: ";
    cout << ans << &#39;\n&#39;;
  }
}
