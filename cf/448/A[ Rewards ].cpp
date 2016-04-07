#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a1,a2,a3,b1,b2,b3, n,a, b;
  while(cin >> a1 >> a2  >> a3 >> b1 >> b2  >> b3  >> n ){
    a = (a1+a2+a3) / 5 + ((a1+a2+a3)%5 != 0);
    b = (b1+b2+b3) / 10 + ((b1+b2+b3)%10 != 0);
    
    if(a+b <= n) cout << "YES\n";
    else cout << "NO\n";
  } 
}
