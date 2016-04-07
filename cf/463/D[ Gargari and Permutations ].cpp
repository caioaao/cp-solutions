#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int pos[6][1001], n, k, memo[1001];;

int dp(int num){
  if(memo[num]) return memo[num];
  
  memo[num] = 1;
  for(int i = 1; i <= n; i++) if(i != num){
    int j;
    for(j = 0; j < k; j++){
      if(pos[j][num] > pos[j][i]) break;
    } 
    if(j == k) memo[num] = max(memo[num], dp(i) + 1);
  }
  return memo[num];
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n >> k;
  int x;
  for(int i = 0; i < k; i++){
    for(int j = 0; j < n; j++){
      cin >> x;
      pos[i][x] = j;
    }
  }
  memset(memo,0,sizeof memo);
  int ans = 1;
  for(int i = 1; i <= n; i++){
    ans = max(ans,dp(i));
  }
  cout << ans << &#39;\n&#39;;
}
