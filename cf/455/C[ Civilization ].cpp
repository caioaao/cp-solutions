#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi p;
int n, m;
void UF(){ p.assign(n,0); for(int i = 0; i < n; i++) p[i] = i; }
int findSet(int a){ return p[a] = a == p[a] ? a : findSet(p[a]); }
bool isSameSet(int a, int b){
  return findSet(a) == findSet(b);
}
void unionSet(int a, int b){ p[findSet(b)] = findSet(a); }

vi visited, d, diam;
vector<vi> AdjList;
int farthest;
void dfs(int u, const int &scc, const int &vis){
  visited[u] = vis;
  if(d[u] > diam[scc]){
    diam[scc] = d[u];
    farthest = u;
  }
  for(int i = 0; i < (int)AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(visited[v] != vis){
      d[v] = d[u] + 1;
      dfs(v,scc,vis);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  int q;
  cin >> n >> m >> q;
  UF();
  AdjList.assign(n,vi());
  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    a--;b--;
    AdjList[a].push_back(b);
    AdjList[b].push_back(a);
    unionSet(a,b);
  }
  d.assign(n,0);
  diam.assign(n,0);
  visited.assign(n,0);
  
  for(int i = 0; i < n; i++) if(visited[i] == 0){
    farthest = i;
    dfs(i,findSet(i),1);
    d[farthest] = 0;
    dfs(farthest,findSet(i), 2);
  }
  int typ;
  while(q--){
    cin >> typ >> a;
    if(typ == 1){
      cout << diam[findSet(--a)] << &#39;\n&#39;;
    }
    else{
      cin >> b;
      a--; b--;
      if(!isSameSet(a,b)){
	diam[findSet(a)] = max(diam[findSet(a)], max(diam[findSet(b)], diam[findSet(a)]/2 + diam[findSet(a)]%2 + diam[findSet(b)]/2 + diam[findSet(b)]%2 + 1));
	unionSet(a,b);
      }
    }
  }
}
