#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  int ans = 0;
  int p, q;
  while(n--){
    cin >> p >> q;
    ans += q-p >= 2;
  }
  cout << ans << &#39;\n&#39;;
}
