#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t, n;
  cin >>t;
  bool hasIt[1000000];
  while(t--){
    memset(hasIt, 0, sizeof hasIt);
    cin >> n;
    int dig, ans = 0;
    while(n--){
      cin >> dig;
      if(!hasIt[dig])ans++;
      hasIt[dig] = true;
    }
    cout << ans << '\n';
  }
}
