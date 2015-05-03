#include <iostream>

using namespace std;
typedef long long ll;

ll powsOf2[10] = {1, 2, 1024, 976371285, 688423210, 905611805, 607723520, 235042059, 255718402, 494499948};

int main(){
	ios_base::sync_with_stdio(false);
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		/*
		ll verif = 1;
		for(ll i = 0; i < N; i++){
			verif = (verif*2)%1000000007;
		} 
		cout << "Debug:" << verif-1 << endl;
		*/
		ll ans = 1, alg;
		for(ll j = 1, i = 1; j <= N; j*=10, i++){
			alg = (N/j)%10;
			//cout << i << ':' << alg << endl;
			for(int k = 0; k < alg; k++) ans = (ans*powsOf2[i])%1000000007;
		}
		cout << (ans > 0 ? ans-1 : 1000000006) << '\n';
	}
}
