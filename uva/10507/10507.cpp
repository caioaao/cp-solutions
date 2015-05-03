#include <bits/stdc++.h>

#define INF 1000

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

map<char, int> cToV;
int n;

vvi AdjList;
vi awaken, indeg, visited, dist;

int bfs(){
  queue<int> q;
  dist.assign(n,0);
  visited.assign(n,0);
  indeg.assign(n,0);
  for(int i = 0; i < n; i++){
    if(awaken[i]){
      dist[i] = 0;
      q.push(i);
    }
  }
  while(!q.empty()){
    int u = q.front(); q.pop();
    
    visited[u] = 1;
    awaken[u] = 1;
    for(int i = 0; i < (int)AdjList[u].size(); i++){
      int v = AdjList[u][i];
      if(!awaken[v] && indeg[v] < 3){
        dist[v] = dist[u]+1;
        if(++indeg[v] >= 3){
          q.push(v);
        }
      }
    }
  }
  int amtAwaken = 0, ret = 0;
  for(int i = 0; i < n; i++){
    if(awaken[i]) amtAwaken++;
    ret = max(ret,dist[i]);
  }
  if(amtAwaken == n) return ret;
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int m;
  char c, c_a, c_b;
  while(cin >> n){
    cin >> m;
    
    cToV.clear();
    int n_u = 0;
    AdjList.assign(n,vi());
    awaken.assign(n,0);
    
    for(int i = 0; i < 3; i++){
      cin >> c;
      cToV[c] = n_u;
      awaken[n_u++] = 1;
    }
    
    int u1, u2;
    for(int i = 0; i < m; i++){
      cin >> c_a >> c_b;
      if(!cToV.count(c_a)){
        cToV[c_a] = n_u++;
      }
      u1 = cToV[c_a];
      
      if(!cToV.count(c_b)){
        cToV[c_b] = n_u++;
      }
      u2 = cToV[c_b];
      
      
      AdjList[u1].push_back(u2);
      AdjList[u2].push_back(u1);
    }
    int ans = bfs();
    
    if(ans == -1){
      cout << "THIS BRAIN NEVER WAKES UP\n";
    }
    else{
      cout << "WAKE UP IN, " << ans << ", YEARS\n";
    }
  }
}
