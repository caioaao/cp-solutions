#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n,m;
  while( cin >> m >> n){
  
    double ans, pl, p, pot;
    ans = pl = pow(1.0/m, n);
    for(int i = 2; i <= m; i++){
      pot = pow(((double)i)/m,n);
      p = pot-pl;
      ans = ans + p*i;
      pl = pot;
    }
    cout << fixed << setprecision(10) << ans << &#39;\n&#39;;
  }
}
