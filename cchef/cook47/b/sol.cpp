#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ii>layers;

int main(){
  ll n,m,h;
  while(cin >> n >> m >> h){
    ll cL = n*m;
    layers.assign(h,ii());
    for(int i = 0; i < h; i++){
      cin >> layers[i].second >> layers[i].first;
    }
    sort(layers.begin(),layers.end());
    ll ans = 0, tbp;
    for(int i = 0; i < h && cL > 0; i++){
      tbp = min(layers[i].second, cL);
      cL -= tbp;
      ans += layers[i].first * tbp;
    }
    if(cL == 0) cout << ans << '\n';
    else cout << "Impossible\n";
  }
}
