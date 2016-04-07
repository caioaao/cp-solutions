#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int x, amt;
  while(cin >> x){
    amt = x;
    for(int i = 1; i < 5; i++){
      cin >> x;
      amt += x;
    }
    if(amt % 5 || amt == 0) cout << "-1\n";
    else cout << amt/5 << &#39;\n&#39;;
  }
}
