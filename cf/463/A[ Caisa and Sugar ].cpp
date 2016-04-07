#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n,s;
  
  cin >> n >> s;
  int d, c, ans = -1;
  while(n--){
    cin >> d >> c;
    if(d < s || (d == s && c == 0)){
      ans = max(ans,( c == 0 ? 0 : 100-c));
    }
  }
  cout << ans << &#39;\n&#39;;
}
