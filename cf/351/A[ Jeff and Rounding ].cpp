#include <bits/stdc++.h>

#define MAXN 2001
#define inf 1e18

using namespace std;
typedef long long ll;

ll n;
ll d;

int main(){
  ios_base::sync_with_stdio(false);
  char dummy;
  while(cin >> n){
    ll v, s = 0, zcnt = 0;
    for(int i = 0; i < 2*n; i++){
      cin >> v >> dummy >> d;
      if(d) s+= d;
      else zcnt++;
    }
    
    ll delt = inf;
    for(int z = max(0ll,zcnt-n); z <= min(n, zcnt); z++){
      ll teste = abs(1000*(n-z) - s);
      //~ cout << "1000*(" << n << &#39;-&#39; << z << ") - " << s << &#39;=&#39;  << teste << &#39;\n&#39;;
      delt = min(delt,teste);
    }
    
    cout << fixed << setprecision(3) << delt/1000. << &#39;\n&#39;;
  }
}
