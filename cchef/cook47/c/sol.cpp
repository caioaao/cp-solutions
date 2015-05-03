#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> v1, v2;

int main(){
  ll n;
  scanf("%lld", &n);
  ll auxv,auxw, sw = 0;
  while(n--){
    scanf("%lld %lld", &auxw, &auxv);
    if(auxw == 2) v2.push_back(auxv);
    else v1.push_back(auxv);
    sw += auxw;
  }
  sort(v1.begin(),v1.end(), greater<ll>());
  sort(v2.begin(),v2.end(), greater<ll>());
  ll n1 = v1.size(), n2 = v2.size();
  if(n1 == 0){
    cout << 0;
    ll ans = 0;
    for(int i = 0; i < n2-1; i++){
      ans += v2[i];
      cout << ' '  << ans << ' ' << ans;
    }
    cout << ' ' << ans+v2.back() << '\n';
    return 0;
  }
  if(n2 == 0){
    cout << v1[0];
    ll ans = v1[0];
    for(int i = 1; i < n1; i++){
      cout << ' '  << (ans+=v1[i]);
    }
    cout << '\n';
    return 0;
  }
  ll w_1 = v1[0], w_2 = 0;
  ll i_1 = 1, i_2 = 0, j_1 = 0, j_2 = 0, i = 1, j = 0; 
  
  cout << w_1;
  
  ll ans1, ans2;
  
  for(ll w = 2; w <= sw; w++){
    ans1 = w_1; ans2 = w_2;
    if(i_1 < n1) ans1 += v1[i_1];
    if(j_2 < n2) ans2 += v2[j_2];
    
    if(ans1 > ans2)
      i = i_1+1, j = j_1;
    else
      i = i_2, j = j_2 + 1;
    i_2 = i_1;
    j_2 = j_1;
    i_1 = i;
    j_1 = j;
    w_2 = w_1;
    w_1 = max(ans1, ans2);
    cout << ' ' << w_1;
  }
  cout << '\n';
}
