#include <iostream>

using namespace std;
typedef long long ll;

ll T, n, r[100001], low, high, mid, soma;

bool can(ll k){
	bool ok = true;
	for(int i = 0; i < n; i++){
		if(r[i]-(i == 0 ? 0 : r[i-1]) == k){
			k--;
		}else if( r[i]-(i == 0 ? 0 : r[i-1]) > k){
			ok = false;
			break;
		}
	}
	return ok;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		cin >> n;
		soma = 0;
		for(int i = 0; i < n; i++){
			cin >> r[i];
			soma += r[i];
		}
		low = 1; high = r[n-1]+n;
		while(high-low > 1){
			mid = (low+high)/2;
			if(can(mid))
				high = mid;
			else
				low = mid;
		}
		cout << "Case " << caso << ": " << (can(low)? low : high) << '\n';
	}
}
