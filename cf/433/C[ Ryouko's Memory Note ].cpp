#include <bits/stdc++.h>

using namespace std;
typedef long long L;
typedef vector<L> vi;

vector<vi> adjList;
L la, x, tot, n, m, d1, d2, du;

L solve(){
  L bst = tot, aux;
  for(L i = 1; i <= n; i++)if(!adjList[i].empty()){
    sort(adjList[i].begin(),adjList[i].end());
    L y = adjList[i][adjList[i].size()/2];
    aux = tot;
    for(size_t j = 0; j < adjList[i].size(); j++){
      aux = aux - abs(adjList[i][j] - i) + abs(adjList[i][j] - y);
    }
    
    //cout << "Merging " << i << " to " << y << &#39;:&#39; << aux << &#39;\n&#39;;
    bst = min(bst, aux);
  }
  return bst;
}


inline void add_e(L a, L b){
  if(a == b) return;
  adjList[a].push_back(b);
  adjList[b].push_back(a);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  while(cin >> n >> m){
    adjList.assign(n+1,vi());
    tot = 0;
    cin >> la;
    for(int i = 1; i < m; i++){
      cin >> x;
      add_e(la,x);
      tot += abs(la-x);
      la = x;
    }
    cout << solve() << &#39;\n&#39;;
  }
}
