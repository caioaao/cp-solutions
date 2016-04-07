#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
stack<ii> st;
vector<int> vals;
int main(){
  ios_base::sync_with_stdio(false);
  
  int n;
  while(cin >> n){
    vals.assign(n,0);
    for(int i = 0; i < n; i++) cin >> vals[i];
    int ttk;
    ii la;
    int ans = 0;
    for(int id = n-1; id >= 0; id--){
      ttk = 0;
      while(true){
        if(st.empty()) break;
        la = st.top();
        if(vals[la.first] >= vals[id]) break;
        ttk = max(ttk+1, la.second);
        st.pop();
      }
      ans = max(ttk, ans);
      st.push(ii(id,ttk));
    }
    
    while(!st.empty()){
      st.pop();
    }
    
    cout << ans << &#39;\n&#39;;
  }
}
