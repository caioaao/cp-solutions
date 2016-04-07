#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ipow(ll a, ll p){
  ll ret = 1;
  while(p){
    ret *= a;
    p--;
  }
  return ret;
}

ll S(ll x){
  ll ret = 0;
  for(ll i = 1; i < 10000000000ll; i*= 10){
    ret += (x/i)%10;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  ll a, b, c, x;
  while(cin >> a >> b >> c){
    vector<ll> ans;
    for(ll sx = 1; sx <= 9*9; sx++){
      x = b*ipow(sx,a)+c;
      if(S(x) == sx && x > 0 && x < 1000000000){
        ans.push_back(x);
      }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << &#39;\n&#39;;
    for(int i = 0; i < (int)ans.size(); i++){
      cout << ans[i] << &#39; &#39;;
    }
  }
}
