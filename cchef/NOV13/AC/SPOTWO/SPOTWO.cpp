#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int ans[22] = {1, 4, 1048576, 499445072,749218516, 614428880, 175895282, 112246098, 663690304, 860291332, 767822271, 998434054, 442059314, 697784813, 461659580, 378518816, 517405155, 386926526, 7743628, 80065005, 367497848, 920828200};


int main(){
	ios_base::sync_with_stdio(false);
	ll T, N;
	cin >> T;
	while(T--){
		cin >> N;
		ll resp = 1;
		for(ll i = 0,minN=1; minN <= N; i++, minN*=2){
			if((N & (1 << i)) != 0)
				resp = (resp*ans[i+1])%1000000007;
		}
		cout << resp << '\n';
	}
}
