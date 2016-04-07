#include <bits/stdc++.h>

#define MAX_N 300001

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll vals[MAX_N], ps[MAX_N+1];


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  
  int n;
  while(cin >> n){
    for(int i = 0; i < n; i++){
      cin >> vals[i];
    }
    
    sort(vals, vals+n);
    ps[0] = vals[0];
    for(int i = 1; i < n; i++){
      ps[i] = ps[i-1] + vals[i];
    }
    
    ll ans = ps[n-1];
    
    for(int i = 0; i < n-1; i++)
      ans += ps[n-1] - (i > 0 ? ps[i-1] : 0);
    
    cout << ans << &#39;\n&#39;;
    
  }
}
