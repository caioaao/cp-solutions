#include <bits/stdc++.h>

#define MAX_N 1001
#define MAX_K 1001

using namespace std;
typedef long long ll;

ll memo[MAX_N][2*MAX_N], n, k, maiV, vals[26];
string s;

inline ll f(int id, int c){
  return vals[s[id]-&#39;a&#39;]*(c+1);
}

ll dp(int id, int ind){
  int kU = ind - id;
  if(id == n && kU == k) return 0;
  if(memo[id][ind] != -1) return memo[id][ind];
  memo[id][ind] = 0;
  if(id < n){
    memo[id][ind] = dp(id+1,ind+1) + f(id,ind);
  }
  if(kU < k){
    memo[id][ind] = max(memo[id][ind], dp(id, ind+1) + maiV*(ind+1));
  }
  return memo[id][ind];
}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> s){
    n = s.size();
    cin >> k;
    cin >> maiV;
    vals[0] = maiV;
    for(int i = 1; i < 26; i++){
      cin >> vals[i];
      if(vals[i] > maiV) maiV = vals[i];
    }
    
    memset(memo, -1, sizeof memo);
    cout << dp(0,0) << &#39;\n&#39;;
  }
}
