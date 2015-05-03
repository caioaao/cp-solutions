#include <iostream>
#include <iomanip>

#define MOD 10000000

using namespace std;
typedef unsigned long long ll;

struct mat{ ll m[2][2]; };

mat mult(const mat a, const mat b){
	mat ret;
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			ret.m[i][j] = 0;
			for(int k = 0; k < 2; k++){
				ret.m[i][j] = (ret.m[i][j] + (a.m[i][k]*b.m[k][j])%MOD)%MOD;
			}
		}
	}
	
	return ret;
}

mat fast_pow(const mat a, ll n){
	if(n == 1) return a;
	mat aux = fast_pow(a,n/2);
	aux = mult(aux,aux);
	if(n % 2 != 0) aux = mult(aux,a);
	return aux;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	mat M, M_pow;
	M.m[1][0] = 1;
	M.m[1][1] = 0;
	
	ll n, l, k;
	
	while(cin >> n >> k >> l){
		
		n/=5;
		
		k = k%MOD;
		l = l%MOD;
		
		M.m[0][0] = k;
		M.m[0][1] = l;
		
		if(n == 1){
			cout << setw(6) << setfill('0') << k << '\n';
			continue;
		}
		
		if(n == 2){
			cout << setw(6) << setfill('0') << (l + (k*k)%MOD)%MOD << '\n';
			continue;
		}
		
		M_pow = fast_pow(M,n-2);
		
		ll ans = ((M_pow.m[0][0]*((l + (k*k)%MOD)%MOD))%MOD + (M_pow.m[0][1]*k)%MOD)%MOD;
		
		cout << setw(6) << setfill('0') << ans << '\n';
	}
}
