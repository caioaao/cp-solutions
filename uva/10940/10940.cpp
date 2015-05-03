#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(false);
	
	ll n;
	while(cin >> n){
		if(n == 0) break;
		
		if(n == 1){
			cout << "1\n";
			continue;
		}
		
		ll po2 = pow(2,floor(log((double)n)/log(2.)));
		//~ cout << po2 << ':';
		ll ans = 2*(n-po2);
		cout << ans << '\n';
	}
}
