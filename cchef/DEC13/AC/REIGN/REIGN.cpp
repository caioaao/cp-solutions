#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define INF 1e15
#define MAX_N 100010

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll N, K;
vll lss, A, lss2;


int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> N >> K;
		lss.assign(N,0);
		lss2.assign(N,0);
		A.assign(N,0);
		ll mnr = 0, soma = 0;
		for(int i = 0; i < N; i++){
			cin >> A[i];
			soma += A[i];
			lss[i] = soma-mnr;
			mnr = min(mnr,soma);
		}
		
		ll mnrInv = 0, somaInv = 0;
		for(int i = N-1; i >= 0; i--){
			somaInv += A[i];
			lss2[i] = somaInv - mnrInv;
			mnrInv = min(mnrInv, somaInv);
		}
		
		
		for(int i = N-2; i >= 0; i--) lss2[i] = max(lss2[i+1],lss2[i]);
		
		ll ans = -INF;
		for(int i = 0; i + 1< N-K; i++) ans = max(ans, lss[i]+lss2[i+K+1]);
		cout << ans << '\n';
	}
}
