#include <iostream>
#include <cmath>
#include <algorithm>
#define EPS 1E-9

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	ll T, M, N, ans, j;
	cin >> T;

	T--;	
	ans = 0;
	cin >> N >> M;
	if(M == 1 || N == 1) cout << 1 << '\n';
	else{
		for(ll i = 1; i <= N; i++){
			j = ((M-1)*i-M+N)/(N-1);
			if(j+M*(i-1) == i+N*(j-1) && j <= M && j >= 1) ans++;
		}
	}
	cout << ans;

	while(T--){
		cout << '\n';
		ans = 0;
		cin >> N >> M;
		if(M == 1 || N == 1) cout << 1 << '\n';
		else{
			for(ll i = 1; i <= N; i++){
				j = ((M-1)*i-M+N)/(N-1);
				if(j+M*(i-1) == i+N*(j-1) && j <= M && j >= 1) ans++;
			}
		}
		cout << ans;
	}
}
