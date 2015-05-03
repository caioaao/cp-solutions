#include <bits/stdc++.h>

#define INF 1e7

using namespace std;
typedef vector<int> vi;

vi digits, visited, dist;
int n;
vector<vi> reachable;
string ds;

queue<int> q;
int bfs(){
  dist.assign(n,INF);
  dist[n-1] = 0;
  q.push(n-1);
  int u, v;
  while(!q.empty()){
    u = q.front(); q.pop();
    if(u == 0) break;
    if(dist[u-1] == INF){
      dist[u-1] = dist[u]+1;
      q.push(u-1);
    }
    if(u < n - 1 && dist[u+1] == INF){
      dist[u+1] = dist[u] + 1;
      q.push(u+1);
    }
    if(visited[digits[u]]) continue;
    visited[digits[u]] = 1;
    for(int i = 0; i < (int)reachable[digits[u]].size(); i++){
      v = reachable[digits[u]][i];
      if(dist[v] == INF){
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }
  return dist[0];
}

int main(){
  ios_base::sync_with_stdio(false);
  
    while(cin >> ds){
      n = ds.size();
      reachable.assign(10,vi());
      digits.assign(n,0);
      visited.assign(10,0);
      for(int i = 0; i < n; i++){
        digits[i] = ds[i] - '0';
        reachable[digits[i]].push_back(i);
      }
      
      cout << bfs() << endl;
    }
}
