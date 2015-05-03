#include <iostream>

using namespace std;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(false);
	ll n, k, amt, dr, r;
	while(cin >> n >> k){
		amt = 0;
		r = 0;
		while(n+r >= k){
			amt+= n;
			dr = (n+r)%k;
			n = (n+r)/k;
			r = dr;
		}
		cout << amt+n << '\n';
	}
}
