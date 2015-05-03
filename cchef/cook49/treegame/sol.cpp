#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

vector<vi> AdjList;
vi d;
int t, n;
queue<int> q;
void bfs(){
  d.assign(n,-1);
  d[0] = 0;
  q.push(0);
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int i = 0; i < (int) AdjList[u].size(); i++){
      int v = AdjList[u][i];
      if(d[v] == -1){
	d[v] = d[u]+1;
	q.push(v);
      }
    }
  }
}

bool cmp(int a, int b){
  if(d[a] > d[b]) return true;
  if(d[a] < d[b]) return false;
  return a < b;
}

set<int, bool(*)(int a, int b)> nds(cmp);
vi visited;
queue<int> q2[2];
int bfs2(){
  visited.assign(n,0);
  int ans = 1;
  if(!nds.empty()){
    ans++;
    nds.erase(*nds.begin());
  }
  bool r = 0;
  q2[0].push(0);
  while(!nds.empty()){
    ans++;
    while(!q2[r].empty()){
      int u = q2[r].front(); q2[r].pop();
      visited[u] = 1;
      for(int j = 0; j < (int)AdjList[u].size(); j++){
	int v = AdjList[u][j];
	if(visited[v] || !nds.count(v)) continue;
	q2[!r].push(v);
	nds.erase(v);
      }
    }
    if(!nds.empty()){
      nds.erase(*nds.begin());
      ans++;
    }
    r ^= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> t;
  while(t--){
    cin >> n;
    AdjList.assign(n,vi());
    int a, b;
    for(int i = 1; i < n; i++){
      cin >> a >> b;
      a--;b--;
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
    }
    while(!q.empty()) q.pop();
    bfs();
    
    nds.clear();
    for(int i = 1; i < n; i++) nds.insert(i);
    
    while(!q2[0].empty()) q2[0].pop();
    while(!q2[1].empty()) q2[1].pop();
    cout << bfs2() << '\n';
  }
}
