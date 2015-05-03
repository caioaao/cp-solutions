#include <iostream>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	long T, n;
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		cout << "Case "<< caso << ": ";
		cin >> n;
		ll comb = (n*(n-1))/2;
		if(comb%2 == 0) cout << comb/2 << '\n';
		else cout << comb << "/2\n";
	}
}
