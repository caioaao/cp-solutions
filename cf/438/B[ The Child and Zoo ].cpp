#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vvi AdjList;
vi vals;
vii ord;
ll ans, v, e;

vi p, added, psize;
void UF(){
  p.assign(v,0);
  psize.assign(v,1);
  for(int i = 0; i < v; i++) p[i] = i;
}
ll findSet(int u){ return p[u] = (p[u] == u ? p[u] : findSet(p[u])); }
bool isSameSet(int u, int v){ return findSet(u) == findSet(v); }
void unionSet(int u, int v){
  psize[findSet(v)] += psize[findSet(u)];
  p[findSet(u)] = findSet(v); 
}
ll unionSize(int u){ return psize[findSet(u)];}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> v >> e){
    vals.assign(v,0);
    AdjList.assign(v,vi());
    ord.assign(v,ii());
    for(int i = 0; i < v; i++){
      cin >> ord[i].first;
      ord[i].second = i;
    }
    int a, b;
    for(int i = 0; i < e; i++){
      cin >> a >> b;
      a--;b--;
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
    }
    UF();
    added.assign(v,0);
    sort(ord.begin(),ord.end(), greater<ii>());
    ans = 0;
    for(int i = 0; i < v; i++){
      ii u = ord[i];
      added[u.second] = 1;
      for(int j = 0; j < (int)AdjList[u.second].size(); j++){
        int vj = AdjList[u.second][j];
        if(added[vj] && !isSameSet(u.second,vj)){
          ans += unionSize(u.second)*unionSize(vj)*u.first;
          unionSet(u.second,vj);
        }
      }
    }
    double ansf = 2.0*ans / (v*(v-1));
    cout << fixed << setprecision(10) << ansf << &#39;\n&#39;;
  }
}
