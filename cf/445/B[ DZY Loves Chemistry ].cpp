#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
long long danger;
vvi AdjList;
vi visited;


void bfs(int s){
  queue<int> q;
  q.push(s);
  int u, v;
  while(!q.empty()){
    u = q.front();q.pop();
    visited[u] = 1;
    for(int i = 0; i < (int) AdjList[u].size(); i++){
      v = AdjList[u][i];
      if(!visited[v]){
	q.push(v);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> n >> m){
    AdjList.assign(n,vi());
    visited.assign(n,0);
    int a, b;
    for(int i = 0; i < m; i++){
      cin >> a >> b;
      a--;b--;
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
    }
    int pot = n;
    for(int i = 0; i < n; i++){
      if(!visited[i]){
	bfs(i);
	pot--;
      }
    }
    danger = 1;
    for(int i = 0; i < pot; i++) danger*=2;
    cout << danger << &#39;\n&#39;;
  }
}
