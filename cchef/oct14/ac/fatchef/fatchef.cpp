#include <bits/stdc++.h>

#define MAXN 100002
#define mod 1000000009

using namespace std;
typedef long long ll;
typedef pair<ll,char> plc;

vector<plc> vals;
int main(){
  ios_base::sync_with_stdio(false);
  
  char c, lc;
  ll t,n,m,y, ly;
  cin >> t;
  while(t--){
    cin >> n >> m;
    if(m == 0){
      cout << "0\n";
      continue;
    }
    vals.assign(m,plc());
    for(int i = 0; i < m; i++) cin >> vals[i].second >> vals[i].first;
    
    sort(vals.begin(), vals.end());
    
    lc = vals[0].second;
    ly = vals[0].first;
    ll ans = 1;
    ll R;
    for(int i = 1; i < m; i++){
      y = vals[i].first;
      c = vals[i].second;
      if(c == lc){
        R = 0;
      }
      else{
        R = y - ly - 1;
      }
      lc = c; ly = y;
      
      ans = (ans*(R+1))%mod;
    }
    
    
    cout << ans << '\n';
  }
}
