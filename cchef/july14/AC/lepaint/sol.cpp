#include <bits/stdc++.h>

#define MAX_K 55
#define MAX_C 101
#define MAX_N 55

using namespace std;
typedef long long ll;

ll n, k, c;

double memo[MAX_K][MAX_C];
bool is_memo[MAX_K][MAX_C];
ll lens[MAX_N];



double dp(ll k_l, ll lc){
  if(k_l == 0) return lc;
  
  if(is_memo[k_l][lc]) return memo[k_l][lc];
  
  is_memo[k_l][lc] = true;
  
  memo[k_l][lc] = dp(k_l-1, lc)/2.0;
  
  for(int i = 0; i < c; i++) memo[k_l][lc] += dp(k_l - 1, (lc*i)%c)/(2*c);
  
  return memo[k_l][lc];
}

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    cin >> n >> c >> k;
    
    memset(lens, 0, sizeof lens);
    
    int l, r;
    for(int i = 0; i < k; i++){
      cin >> l >> r;
      l--; r--;
      for(int j = l; j <= r; j++) lens[j]++;
    }
    
    double ans = 0;
    memset(is_memo, 0, sizeof is_memo);
    
    for(int i = 0; i < n; i++){
      ans += dp(lens[i], 1);
    }
    cout << fixed << setprecision(12) << ans << '\n';
  }
}
