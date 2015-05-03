#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi p, mai;

int findSet(int u){ return p[u] = (p[u] == u ? u : findSet(p[u])); }
bool isSameSet(int u, int v){ return findSet(u) == findSet(v); }
int findMax(int u){ return mai[findSet(u)]; }
void unionSet(int u, int v){
  if(findMax(u) > findMax(v)){
    mai[findSet(v)] = mai[findSet(u)];
    p[findSet(v)] = findSet(u);
  }
  else if(findMax(u) < findMax(v)){
    mai[findSet(u)] = mai[findSet(v)];
    p[findSet(u)] = findSet(v);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int t, n, q;
  cin >> t;
  while(t--){
    cin >> n;
    mai.assign(n,0);
    p.assign(n,0);
    for(int i = 0; i < n; i++){
      p[i] = i;
      cin >> mai[i];
    }
    
    cin >> q;
    int qt, x, y;
    while(q--){
      cin >> qt >> x;
      if(qt == 0){
        cin >> y;
        x--; y--;
        if(isSameSet(x,y)){
          cout << "Invalid query!\n";
          continue;
        }
        unionSet(x,y);
      }
      else{
        cout << findSet(x-1)+1 << '\n';
      }
    }
  }
}
