#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  double p, k, dx;
  vector<double> ps;
  while(cin >> n){
    ps.assign(n,0);
    for(int i = 0; i < n; i++){
      cin >> ps[i];
    }
    
    sort(ps.begin(), ps.end(), greater<double>());
    p = ps[0];
    k = 1.0-ps[0];
    for(int i = 1; i < n; i++){
      dx = ps[i]*(k-p);
      if(dx > 0){
        p += dx;
        k *= (1-ps[i]);
      }
      else{
        break;
      }
    }
    cout << fixed << setprecision(12) << p << &#39;\n&#39;;
  }
}
