#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n, aux, ans, amt;
  while(cin >> n){
    ans = amt = 0;
    while(n--){
      cin >> aux;
      if(aux != 0) amt++;
      else amt = 0;
      
      ans = max(ans,amt);
    }
    cout << ans << '\n';
  }
}
