#include <stdio.h>
typedef long long ll;

ll powsOf2[10] = {1, 2, 1024, 976371285, 688423210, 905611805, 607723520, 235042059, 255718402, 494499948};

int main(){
	int T, N;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&N);
		/*
		ll verif = 1;
		for(ll i = 0; i < N; i++){
			verif = (verif*2)%1000000007;
		} 
		cout << "Debug:" << verif-1 << endl;
		*/
		ll ans = 1, alg, j = 1, i = 1;
		for(; j <= N; j*=10, i++){
			alg = (N/j)%10;
			//cout << i << ':' << alg << endl;
			int k = 0;
			for(; k < alg; k++) ans = (ans*powsOf2[i])%1000000007;
		}
		printf("%lld\n",(ans > 0 ? ans-1 : 1000000006));
	}
}
