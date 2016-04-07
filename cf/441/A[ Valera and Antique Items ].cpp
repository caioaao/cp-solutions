#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n, v;
  cin >> n >> v;
  vector<int> ans;
  int m, x, aux;
  for(int i = 0; i < n; i++){
    cin >> x >> m;
    for(int j = 1; j < x; j++){
      cin >> aux;
      m = min(m,aux);
    }
    if(m < v) ans.push_back(i+1);
  }
  cout << ans.size() << &#39;\n&#39;;
  bool first = true;
  for(int i = 0; i < (int)ans.size(); i++){
    if(!first) cout << &#39; &#39;;
    first = false;
  
    cout << ans[i];
  }
}
