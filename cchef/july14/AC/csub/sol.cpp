#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int t, n;
  cin >> t;
  while(t--){
    cin >> n;
    char c;
    int cnt = 0;
    long long ans = 0;
    while(n--){
      cin >> c;
      if(c == '1') ans += ++cnt;
    }
    cout << ans << '\n';
  }
}
