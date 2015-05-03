#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll T, squa, intP, N;
	cin >> T;
	while(T--){
		cin >> N;
		if(N == 1){
			cout << "0.000\n";
			continue;
		}
		
		squa = N*N;
		intP = (N-1)*4;
		double ans = intP + sqrt(2)*(squa-intP);
		cout << fixed << setprecision(3) << ans << '\n';
	}
}
