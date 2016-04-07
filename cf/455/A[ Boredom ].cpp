#include <bits/stdc++.h>

#define MAX_N 100001

using namespace std;
typedef long long ll;


ll amt[MAX_N], vals[MAX_N], n;
ll memo[MAX_N];

ll dp(int id){
  if(id == n) return 0;
  if(id == n-1) return vals[id]*amt[vals[id]];
  if(memo[id] != -1) return memo[id];
  
  
  if(vals[id+1] == vals[id]+1){
    memo[id] = max(dp(id+1), dp(id+2)+vals[id]*amt[vals[id]]);
  }
  else{
    memo[id] = dp(id+1)+vals[id]*amt[vals[id]];
  }
  return memo[id];
}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> n){
    memset(amt, 0, sizeof amt);
    int x, c = 0;
    for(int i = 0; i < n; i++){
      cin >> x;
      if(amt[x]++ == 0){
        vals[c++] = x;
      }
    }
    n = c;
    
    sort(vals,vals+n);
    memset(memo,-1, sizeof memo);
    cout << dp(0) << &#39;\n&#39;;
  }
}
