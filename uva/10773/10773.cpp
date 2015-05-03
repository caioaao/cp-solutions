#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(false);
	ll u, v, d, t;
	double vp;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		cout << "Case " << caso << ": ";
		cin >> d >> v >> u;
		if(v >= u || u == 0 || v == 0){
			cout << "can't determine\n";
			continue;
		}
		
		vp = sqrt(u*u-v*v);
		cout << fixed << setprecision(3) << (u*d-vp*d)/(vp*u) << '\n';
	}
}
