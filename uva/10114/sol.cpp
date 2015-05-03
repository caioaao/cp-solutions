#include <bits/stdc++.h>

#define EPS 1e-12

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int ps;
  double down_p, loan, ndeps, car_v, money_left, parcela;
  vector<int> dep_m;
  vector<double> dep_v;
  while(cin >> ps >> down_p >> loan >> ndeps, ps >= 0){
    dep_m.assign(ndeps,0);
    dep_v.assign(ndeps,0);
    
    for(int i = 0; i < ndeps; i++){
      cin >> dep_m[i] >> dep_v[i];
    }
    
    car_v = (down_p + loan)*(1.0-dep_v[0]);
    parcela = loan/ps;
    money_left = loan;
    int ans = 1;
    double last_dep = dep_v[0];
    
    for(int dep_i = 1; car_v <= money_left; ans++){
      if(dep_i < ndeps){
        if(dep_m[dep_i] == ans){
          last_dep = dep_v[dep_i];
          dep_i++;
        }
      }
      car_v *= (1.0-last_dep);
      if(ans <= ps)
        money_left -= parcela;
    }
    ans--;
    cout << ans << (ans != 1 ? " months\n" : " month\n");
  }
}
