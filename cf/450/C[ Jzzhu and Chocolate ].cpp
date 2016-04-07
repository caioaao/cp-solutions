#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  long long n, m, k;
  while(cin >> n >> m >> k){
    if(n > m) swap(n,m);
    long long x, y, ans = 0, lim = min((long long)round(sqrt(m)), k) + 1;
    
    for(long long i = 1; i <= lim; i++){
      x = i;
      y = k - x + 2;
      //~ cout << x << &#39;,&#39; << y << endl;
      if(!(y > k+1 || y <= 0)){
        //~ cout << "ok" << endl;
        ans = max(ans, (m/x)*(n/y));
      }
      x = m/x;
      y = k - x + 2;
      //~ cout << x << &#39;,&#39; << y << endl;
      if(x == 0 || x > k + 1 || y > k + 1 || y <= 0) continue;
      //~ cout << "ok" << endl;
      ans = max(ans, (m/x)*(n/y));
    }
    
    lim = min((long long)round(sqrt(n)), k) + 1;
    for(long long i = 1; i <= lim; i++){
      y = i;
      x = k - y + 2;
      //~ cout << x << &#39;,&#39; << y << endl;
      if(!(x > k+1 || x <= 0)){
        //~ cout << "ok" << endl;
        ans = max(ans, (m/x)*(n/y));
      }
      y = n/y;
      x = k - y + 2;
      //~ cout << x << &#39;,&#39; << y << endl;
      if(y == 0 || y > k + 1 || x > k + 1 || x <= 0) continue;
      //~ cout << "ok" << endl;
      ans = max(ans, (m/x)*(n/y));
    }
    
    if(ans == 0) cout << -1 << &#39;\n&#39;;
    else cout << ans << &#39;\n&#39;;
  }
}
