#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll vals[1000000], n;
map<ll,ll> amt;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(cin >> n){
    amt.clear();
    
    for(int i = 0; i < n; i++){
      cin >> vals[i];
      if(!amt.count(vals[i]))
	amt[vals[i]] = 1;
      else
	amt[vals[i]]++;
    }
    
    sort(vals, vals+n);
    
    ll am = vals[n-1] - vals[0], ans = 0;
    
    for(map<ll,ll>::const_iterator it = amt.begin(); it != amt.end(); ++it)
      if(amt.count(am + it->first)){
	if(am != 0){
	  ans += it->second * amt[am + it->first];
	}
	else{
	  ans += (it->second * (it->second - 1))/2;
	}
      }
    
    cout << am << &#39; &#39; << ans << &#39;\n&#39;;
  }
}
