#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll vals;

inline ll root(ll a, ll n)
{
  double p = pow(a,1.0/n);
  ll lo = p,
    hi = p + .5;
    
    if(lo == hi || pow(hi,n) <= a) return hi;
    return lo;
}


int main(){
  int t, n, q;
  ll x, miters = 0, totSoma;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d", &n, &q);
    
    vals.assign(n,0);
    totSoma = 0;
    for(int i = 0; i < n; i++){
      scanf("%lld",&vals[i]);
      totSoma = (totSoma + vals[i])%MOD;
    }
    bool first = true;

    while(q--){
      if(!first) printf(" ");
      first = false;
      
      scanf("%lld",&x);
      
      ll ans = totSoma, d = x;
      int i = 0;
      
      ll iters = 0;
      while(d > 1ll && i < n){
        iters++;
        ans = (ans + (((d-1)%MOD)*vals[i++])%MOD)%MOD;
        d = root(x,i+1);
        //~ cout << d << '^' << i+1 << "<=" << x << endl;
        
        //~ d = (ll)pow(x,1./(i+1)) + 1;
        //~ while(fast_pow(d,i+1) > x)d--;
        //~ cout << d <<  ' ';
      }
      //~ cout << iters << endl;
      printf("%lld",(ans < 0 ? (MOD + ans) : ans));
      miters = max(miters, iters);
    }
    printf("\n");
  }
  //~ cout << "Max iteracoes " << miters;
}
