#include <bits/stdc++.h>

#define MAXN 100001
#define mod 1000000007

using namespace std;
typedef long long L;

L mul_inv(L a, L b)
{
    L b0 = b, t, q;
    L x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}



L F[MAXN], _F[MAXN];
void prec(){
  F[0] = _F[0] = 1;
  for(L i = 1; i <MAXN; i++){
    F[i] = F[i-1]*i;
    if(F[i] >= mod) F[i] %= mod;
    
    _F[i] = _F[i-1] * mul_inv(i, mod);
    if(_F[i] >= mod) _F[i] %= mod;
  }
}


map<L,L> memo[MAXN];


inline L nCr(L x, L y){
  L num = F[x], den = _F[y] * _F[x-y];
  if(den >= mod) den %= mod;
  num *= den;
  if(num >= mod) num %= mod;
  return num;
}

L dp(L n, L f){
  if(n < f) return 0; if(n == f) return 1;
  
  if(memo[n].count(f)) return memo[n][f];
  
  L & res = memo[n][f] = nCr(n-1,f-1);
  
  L g = 2;
  for(; g*g < n; g++) if(n%g == 0){
    res -= dp(n/g,f) + dp(g,f);
    if(res >= mod || res <= mod) res %= mod;
  }
  if(g*g == n) res -= dp(g,f);
  if(res >= mod || res <= mod) res %= mod;
  
  return res;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  
  int q;
  L N,F;
  cin >> q;
  while(q--){
    cin >> N >> F;
    if(F == 1){
      cout << (N == 1) << "\n";
      continue;
    }
    L res = dp(N,F);
    if(res < 0) res += mod;
    if(res >= mod) res %= mod;
    cout << res << &#39;\n&#39;;
  }
}
