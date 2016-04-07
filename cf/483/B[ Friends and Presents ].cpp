#include <bits/stdc++.h>

using namespace std;
typedef long long L;
typedef double D;

L x,y;
//bool tst;
bool check(L v, L c1, L c2){
  c1 -= (v/y - v/(x*y)); c2 -= (v/x - v/(x*y));
  //if(tst){
    //cout << "Multiplos somente de " << x << ": " << (v/x - v/(x*y)) << &#39;\n&#39;;
    //cout << "Multiplos somente de " << y << ": " << (v/y - v/(x*y)) << &#39;\n&#39;;
  //}
  v -= (v/x + v/y - v/(x*y));
  return max(c1,0ll) + max(c2,0ll) <= v;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //tst = false;
  L c1,c2;
  while(cin >> c1 >> c2 >> x >> y){
    L lo = 1ll, hi = (1ll<<60), mi, ans = (1ll<<60);
    while(hi > lo){
      mi = (hi+lo)/2;
      if(check(mi, c1, c2)){
        ans = min(ans,mi);
        hi = mi;
      }
      else lo = mi + 1;
    }
    //tst = true;
    check(ans, c1, c2);
    //tst = false;
    cout << ans << &#39;\n&#39;;
  }
}
