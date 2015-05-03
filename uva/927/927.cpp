#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	stringstream buffer;
	string line;
	int coef[21], d, k, T, i;
	cin >> T;
	while(T--){
		cin >> i;
		for(int iii = 0; iii <= i; iii++){
			cin >> coef[iii];
		}
		cin >> d >> k;
		int ki = 0, c = 0;
		for(; ki < k; c++){
			ki+= d*c;
		}
		c--;
		//cout << c << endl;
		ll ans = coef[0];
		for(int c2 = 1; c2 <= i; c2++){
		//	cout << coef[c2] << ' ';
			ans+= coef[c2]*pow(c, c2);
		}
		cout << ans << '\n';
	}
}
