#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  
  int t;
  string s;
  cin >> t;
  while(t--){
    cin >> s;
    int p = 1;
    ll ans = 1;
    for(size_t i = 0; i < s.size(); i++, p ^= 1){
      if(p)
        ans = (ans*2 + (s[i] == 'l' ? 0 : 2))%MOD;
      else
        ans = (ans*2 + (s[i] == 'l' ? -1 : 1))%MOD;
    }
    cout << ans << '\n';
  }
}
