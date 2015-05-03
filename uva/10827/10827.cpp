#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, t;
	cin >> t; 
	ll sums[150][150], ns[75][75];
	while(t--){
		cin >> n;
		ll x, answ = -127*n*n*2, sum = 0, sum2;
		for(int i = 0; i < 2*n; i++){
			for(int j = 0; j < 2*n; j++){
				if(i < n && j < n){
					cin >> x;
					ns[i][j] = x;
				}
				else
					x = ns[i%n][j%n];

				sum = x + (i ? sums[i-1][j] : 0 ) + (j ? sums[i][j-1] : 0) - (i && j ? sums[i-1][j-1] : 0);
				sums[i][j] = sum;
				
				for(int k = i; k >= i-n && k >= -1; k--){
					for(int l = j; l >= j-n && l >=-1; l--){
						sum2 = sums[i][j] - (k >= 0 ? sums[k][j] : 0) - (l >= 0 ? sums[i][l] : 0) + (k >= 0 && l >= 0 ? sums[k][l] : 0);
						answ = max(sum2,answ);
					}
				}
			}
			
			
		}
		
		cout << answ << '\n';
	}
}
