#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll T, n, ans;
	vll vals;
	cin >> T;
	while(T--){
		cin >> n;
		
		vals.assign(n,0);
		
		for(ll i = 0; i < n; i++)
			cin >> vals[i];
		
		sort(vals.begin(), vals.end());
		ans = 0;
		for(ll i = 0; i < n; i++){
			ans += i;
		}
		cout << ans << '\n';
	}
}
