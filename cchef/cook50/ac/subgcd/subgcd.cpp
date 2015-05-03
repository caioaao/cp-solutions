#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }

int main(){
  int t, n, a;
  cin >> t;
  while(t--){
    cin >> n;
    int g = 0;
    for(int i = 0; i < n; i++){
      cin >> a;
      g = gcd(a,g);
    }
    if(g == 1)
      cout << n << '\n';
    else
      cout << "-1\n";
  }
}
