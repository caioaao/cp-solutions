#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;


int n, m, scc_root;
vi par, ea, eb, path,visited;
vector<vi> AdjList;


vi uf_p, uf_cnt;
void UF(){
  uf_p.assign(n,0);
  uf_cnt.assign(n,0);
  for(int i = 0; i < n; i++){
    uf_p[i] = i;
    uf_cnt[i] = par[i];
  }  
}
int findSet(int a){ return uf_p[a] = (uf_p[a] == a ? a : findSet(uf_p[a])); }
bool isSameSet(int a, int b){ return findSet(a) == findSet(b); }
int unionSet(int a, int b){
  if(par[b]) swap(a,b);
  if(!isSameSet(a,b)){
    uf_cnt[uf_p[a]] += uf_cnt[uf_p[b]];
    uf_p[uf_p[b]] = uf_p[a];
  }
  return uf_cnt[uf_p[a]];
}

void dfs(int u, int p){
  visited[u] = 1;
  path.push_back(u);
  par[u] = !par[u];
  
  for(int i = 0; i < (int)AdjList[u].size(); i++){
    int v= AdjList[u][i];
    if(visited[v]) continue;
    dfs(v,u);
    
    path.push_back(u);
    par[u] = !par[u];
  }
  if(par[u] && p != -1){
    path.push_back(p);
    par[p] = !par[p];
    
    path.push_back(u);
    par[u] = !par[u];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(cin >> n >> m){
    ea.assign(m,0);
    eb.assign(m,0);
    
    for(int i = 0; i < m; i++){
      cin >> ea[i] >> eb[i];
      ea[i]--;eb[i]--;
    }
    
    par.assign(n,0);
    int tot_cnt = 0;
    for(int i = 0; i < n; i++){
      cin >> par[i];
      if(par[i]) scc_root = i;
      tot_cnt += par[i];
    }
    
    if(tot_cnt == 0){
      cout << "0\n";
      continue;
    }
    
    UF();
    AdjList.assign(n,vi());
    int max_cnt = 1, ci;
    for(int i = 0; i < m; i++){
      AdjList[ea[i]].push_back(eb[i]);
      AdjList[eb[i]].push_back(ea[i]);
      
      ci = unionSet(ea[i],eb[i]);
      if(ci > max_cnt){
        max_cnt = ci;
        scc_root = findSet(ea[i]);
      }
    }
    if(max_cnt < tot_cnt){
      cout << "-1\n";
      continue;
    }
    path.clear();
    visited.assign(n,0);
    dfs(scc_root,-1);
    int i;
    if(par[scc_root]){
      i = 1;
      cout << path.size()-1 << &#39;\n&#39;;
    }
    else{
      i = 0;
      cout << path.size() << &#39;\n&#39;;
    }
    for(; i < (int)path.size(); i++){
      cout << path[i]+1 << &#39; &#39;;
    }
    cout << &#39;\n&#39;;
  }
}
