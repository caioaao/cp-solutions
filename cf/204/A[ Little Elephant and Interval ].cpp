#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll l, r;

ll bt(ll beg, ll casa){
  ll lo = beg, hi = beg+1, pot = 1;
  for(int i = 0; i < casa; i++) lo *= 10, hi *= 10, pot*=10;
  
  lo += beg;
  hi -= 10-beg;
  
  //~ cout << lo << &#39; &#39; << hi << &#39;:&#39;;
  if(lo > r || hi < l) return 0;
  
  if(lo >= l && hi <= r){
    return (hi%pot)/10 - (lo%pot)/10 + 1;
  }
  lo = max(l,lo);
  hi = min(hi,r);
  if(lo%10 < beg){
    lo = lo/10;
    lo = lo*10 + beg;
  }
  else if(lo%10 > beg){
    lo = lo/10 + 1;
    lo = lo*10 + beg;
  }
  
  if(hi%10 < beg){
    hi = hi/10 - 1;
    hi = hi*10 + beg;
  }
  else if(hi%10 > beg){
    hi = hi/10;
    hi = hi*10 + beg;
  }
  
  //~ cout << lo << &#39; &#39; << hi;
  if( hi < lo) return 0;
  return (hi%pot)/10 - (lo%pot)/10 + 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> l >> r){
    ll ans = 0;
    for(int i = 1; i < 10; i++){
      if(i >= l && i <= r) ans++;
      
      for(int j = 1; j < 18; j++){
        ans += bt(i,j);
        //~ cout << bt(i,j) << endl;
      }
    }
    cout << ans << &#39;\n&#39;;
  }
}
