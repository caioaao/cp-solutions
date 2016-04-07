#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n, d, ans, aux;
  while(cin >> n >> d){
    for(int i = 0; i < n; i++){
      cin >> aux;
      d -= aux;;
    }
    d -= (n-1)*10;
    ans = (n-1)*2;
    if(d < 0){
      cout << "-1\n";
      continue;
    }
    ans += d/5;
    cout << ans << &#39;\n&#39;;
  }
}
