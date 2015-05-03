#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll delta(ll x, bool y){
  if(!y) return ((ll)(x/2)) + 3*((ll)((x+1)/2));
         return (ll)((x+1)/2) + 3*((ll)(x/2));
}

int main(){
  ios_base::sync_with_stdio(false);
  ll t, x, y;
  
  cin >> t;
  while(t--){
    cin >> x >> y;
    
    x = abs(x);
    y = abs(y);
    
    ll ans = 2*min(x,y);
    
    if(x < y){ // dist vertical
      ans += delta(y, !(x%2)) - delta(x, !(x%2));
    }
    else if(x > y){ // dist horizontal
      //~ cout << delta(x, y%2) << ' ' << delta(y, y%2) << endl;
      ans += delta(x, y%2) - delta(y, y%2);
    }
    cout << ans << '\n';
  }
}
