#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll n,m,k;
  
inline ll count(ll x){
  ll ret = 0;
  for(ll i = 1; i <= n; i++){
    ret += min(x/i,m);
    if(x < i) break;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  
  while(cin >> n >> m >> k){
    if(n > m) swap(n,m);
    
    ll lo = 1, hi = n*m, ct, mi;
    
    while(lo < hi){
      mi = (hi+lo)/2;
    
      ct = count(mi);
    
      if(ct < k) lo = mi + 1;
      else hi = mi;
    }
      cout << lo << &#39;\n&#39;;
  }
}
