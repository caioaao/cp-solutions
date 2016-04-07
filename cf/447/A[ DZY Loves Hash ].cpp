#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ll n, p;
  vector<bool>  hasI;
  while(cin >> p >> n){
    hasI.assign(p,0);
    bool had = false;
    ll x;
    for(int i = 0; i < n; i++){
      cin >> x;
      if(hasI[x%p] && !had){
	 cout << i+1 << &#39;\n&#39;;
	 had= true;
      }
      hasI[x%p] = true;
    }
    if(!had) cout << "-1\n";
  }
}
