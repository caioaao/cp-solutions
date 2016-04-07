#include <bits/stdc++.h>

#define MAX_N 100001

using namespace std;
typedef long long ll;

ll amt[27];


int main(){
  ios_base::sync_with_stdio(false);
  
  ll n, k;
  while(cin >> n >> k){
    memset(amt, 0, sizeof amt);
    char c;
    for(int i = 0; i < n; i++){
      cin >> c;
      amt[c-&#39;A&#39;]++;
    }
    sort(amt, amt+27, greater<ll>());
    ll ans = 0, i = 0;
    while(k > 0){
      ll d = min(k, amt[i]);
      k -= d;
      ans += d*d;
      i++;
    }
    cout << ans << &#39;\n&#39;;
  }
}
