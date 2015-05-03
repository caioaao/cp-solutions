#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, x, y;
  cin >> t;
  while(t--){
    cin >> x >> y;
    if((y%2 == 0 && ((y <= 0 && x >= y && x <= 1-y) || (y > 0 && x >= -y && x <= y-1))) ||
      ((x > 0 && x%2 == 1 && y >= 1-x && y <= 1+x) || (x <= 0 && x%2 == 0 && y >= x && y <= -x))){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}
