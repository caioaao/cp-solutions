#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll c[3], tot, nok2, nok1, ok, x, aux, ans;

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> c[0] >> c[1] >> c[2]){
    sort(c,c+3);
    tot = c[0] + c[1] + c[2];
    nok2 = min(tot/3,c[2]);
    c[2] -= nok2;
    nok1 += min(c[2],nok2);
    nok2 -= min(c[2],nok2);
    c[2] = 0;
    x = c[0]+c[1];
    aux = min(x,nok1);
    x -= aux; nok1 -= aux;
    ans = aux;
    aux = min(x/2, nok2);
    ans += aux;
    
    cout << ans << &#39;\n&#39;;
  }
}
