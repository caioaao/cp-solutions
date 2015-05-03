#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll vals;

ll maxHi[100] = {0,1152921504606846976ll,1073741824ll,1048576,32768,4096,1024,380,181,101,64,43,32,24,19,16,13,11,10,8,8,7,6,6,5,5,4,4,4,4,4,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

inline ll fast_pow(ll a, ll b){
  ll result = 1;

  while (b){
    if (b%2==1){
      result *= a;
    }
    b /= 2;
    a *= a;
  }

  return result;
}

inline ll root(ll a, ll n)
{
  ll hi = maxHi[n],
    lo = 1, mi, aux;
  
  bool c = true;
  while(hi != lo && c == true){
    if(hi == lo+1) break;
    
    c = false;
    mi = (hi+lo)/2;
    aux = fast_pow(mi,n);
    if(aux > a){
      if(hi != mi) c = true;
      hi = mi;
    }
    else if(aux == a){
      return mi;
    }
    else{
      if(lo != mi) c = true;
      lo = mi;
    }
  }
  if(fast_pow(hi,n) <= a){
    return hi;
  }
  return lo;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t, n, q;
  ll x, miters = 0, totSoma;
  cin >> t;
  while(t--){
    cin >> n >> q;
    
    vals.assign(n,0);
    totSoma = 0;
    for(int i = 0; i < n; i++){
      cin >> vals[i];
      totSoma = (totSoma + vals[i])%MOD;
    }
    bool first = true;

    while(q--){
      if(!first) cout << " ";
      first = false;
      
      cin >> x;
      
      ll ans = totSoma, d = x;
      int i = 0;
      
      ll iters = 0;
      while(d > 1ll && i < n){
        iters++;
        ans = (ans + (((d-1)%MOD)*vals[i++])%MOD)%MOD;
        d = root(x,i+1);
      }
      cout << (ans < 0 ? (MOD + ans) : ans);
      miters = max(miters, iters);
    }
    cout << "\n";
  }
}
