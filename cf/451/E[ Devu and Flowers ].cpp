#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;
ll vals[21];

ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}


ll nCr(ll n, ll r){
  //~ cout << n << &#39; &#39; << r << endl;
  ll ans = 1;
  for(ll i = n; i > r; i--){
    ans = (ans*(i%MOD))%MOD;
  }
  for(ll i = 2; i <= n-r; i++){
    ans = (ans*mul_inv(i,MOD))%MOD;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  ll n, k;
  while(cin >> k >> n){
    
    for(int i = 0; i < k; i++) cin >> vals[i];
    
    ll ans = 0,som, s;
    bool even;
    for(int bm = 0; bm < (1 << k); bm++){
      som = 0;
      
      even = true;
      for(int i = 0; i < k; i++) if((1<<i)&bm){
	even=!even;
	som += vals[i]+1;
      }
      
      if(som > n){
	s = 0;
      }
      else if(som == n){
	s = 1;
      }
      else{
	s = nCr(n-som+k-1,n-som);
      }
      
      //~ cout << bm << &#39;:&#39; << nCr(n - som + k - 1,n - som) << &#39;,&#39; << som << endl;
      if(even){
	ans = (ans + s)%MOD;
      }
      else{
	ans = (ans - s)%MOD;
      }
    }
    
    if(ans < 0){
      ans += MOD;
    }
    
    cout << ans << &#39;\n&#39;;
  }
}
