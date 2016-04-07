#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll t, n, k, ng, dv1, dv2, dv3;
ll vals[3];
bool can(ll d1, ll d2){
  // checar se essa diferenca eh valida para k jogos
  vals[0] = k + d1 + d2;
  vals[1] = k + d2;
  vals[2] = k;
  sort(vals, vals+3);
  vals[1] -= vals[0];
  vals[2] -= vals[0];
  vals[0] = 0;
  
  if(vals[0] + vals[1] + vals[2] > k
   || (vals[0]+vals[1]+vals[2] - k)%3 != 0){
    return false;
  }
  
  if(ng < 2*d1 + d2){
    return false;
  }
  else if((ng - (2*d1+d2))%3 != 0){
    return false;
  }
  else{
    dv1 = (ng - (2*d1+d2))/3;
    dv2 = dv1 + d1;
    dv3 = dv1 + d1 + d2;
    if(dv1 < 0 || dv2 < 0 || dv3 < 0) return false;
  }
  //~ cout << dv1 << &#39;+&#39; << dv2 << &#39;+&#39; << dv3 << &#39;=&#39; << dv1+dv2+dv3 << &#39;=&#39; << ng << endl;
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  ll d1, d2;
  cin >> t;
  while(t--){
    cin >> n >> k >> d1 >> d2;
    ng = n - k;
    // + +
    if(can(d1,d2) || can(d1,-d2) || can(-d1,d2) || can(-d1,-d2)){
      cout << "yes\n";
    }
    else{
      cout << "no\n";
    }
  }
}
