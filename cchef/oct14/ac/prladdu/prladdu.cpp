#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t, n;
  cin >> t;
  ll tot, dif, d;
  while(t--){
    cin >> n;
    tot = dif = 0;
    for(int i = 0; i < n; i++){
      tot += abs(dif);
      cin >> d;
      dif+=d;
    }
    cout << tot << '\n';
  }
}
