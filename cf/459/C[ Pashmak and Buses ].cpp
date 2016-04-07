#include <bits/stdc++.h>

#define MAX_D 1001

using namespace std;
typedef long long ll;


ll n, k, d;

ll getp(ll x, ll p){
  ll ret = 1;
  while(p-- && ret){
    ret *= x;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> n >> k >> d){
    ll aux = 1;
    for(int i = 0; i < d && aux <= n; i++,aux*=k) ;
    if(aux < n){
      cout << "-1\n";
      continue;
    }
    for(ll i = 1, cyc = 1; i <= d; i++){
      for(int j = 0; j < n; j++){
        cout << (j%(cyc*k))/cyc + 1 << &#39; &#39;;
      }
      cout << &#39;\n&#39;;
      if(cyc <= n){
        cyc *= k;
      } 
    }
  }
}
