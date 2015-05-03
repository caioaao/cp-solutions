#include <bits/stdc++.h>

#define mod 1000000007
#define MAX_N 1000001

using namespace std;
typedef long long ll;

ll mul_inv(ll a)
{
  ll b = mod;
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


int main(){
  ios_base::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll di = mul_inv(120);
  ll ans = 0;
  ll N,aux;
  for(ll x = 12; x < n; x+=2){
    N = x/2-1;
    aux = di;
    for(ll i = N; i >= N-4; i--){
      aux *= i;
      if(aux >= mod) aux %= mod;
    }
    ans += aux;
    if(ans >= mod) ans %= mod;
  }
  cout << ans << '\n';
}
