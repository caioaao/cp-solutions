#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> AdjMat, AdjList;
int n;

vector<int> visited, outdeg;

vector<pair<int,int> > nes;

priority_queue<int> q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  
  AdjMat.assign(n,vi(n,0));
  AdjList.assign(n,vi(n,0));
  outdeg.assign(n,0);
  char c;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> c;
      if(c == '1'){
        // adjList reversa
        AdjList[j].push_back(i);
        outdeg[i]++;
      }
      AdjMat[i][j] = (c == '1');
    }
  }
  
  for(int i = 0; i < n; i++){
    if(outdeg[i] == 0) q.push(i);
  }
  visited.assign(n,0);
  
  while(!q.empty()){
    int u = q.top(); q.pop();
    visited[u] = 1;
    for(int i = 0; i < n; i++)if(!visited[i] && !AdjMat[i][u]){
      nes.push_back(make_pair(i,u));
    }
    for(int i = 0; i < (int)AdjList[u].size(); i++){
      int v = AdjList[u][i];
      if(--outdeg[v] == 0){
        q.push(v);
      }
    }
  }

  sort(nes.begin(), nes.end());
  cout << nes.size() << '\n';
  for(int i = 0; i < (int)nes.size(); i++){
    cout << nes[i].first+1 << ' ' << nes[i].second+1 << '\n';
  }
}
