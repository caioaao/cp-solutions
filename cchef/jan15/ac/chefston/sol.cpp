#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;
typedef long long ll;

ll A[MAXN];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    ll n,k, Bi, ans = 0;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }

    for(int i = 0; i < n; i++){
      cin >> Bi;
      ans = max(ans, (k/A[i])*Bi);
    }
    cout << ans << '\n';
  }
}
