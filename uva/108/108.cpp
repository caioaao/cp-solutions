#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n; 
	while(cin >> n){
		vector<vll> sums;
		ll x, answ = -127*n*n, sum = 0, sum2;
		for(int i = 0; i < n; i++){
			sums.push_back(vll());
			for(int j = 0; j < n; j++){
				cin >> x;
				sum = x + (i ? sums[i-1][j] : 0 ) + (j ? sums[i][j-1] : 0) - (i && j ? sums[i-1][j-1] : 0);
				sums[i].push_back(sum);
				answ = max(sums[i][j],answ);
				for(int k = i; k >= -1; k--){
					for(int l = j; l >= -1; l--){
						sum2 = sums[i][j] - (k >= 0 ? sums[k][j] : 0) - (l >= 0 ? sums[i][l] : 0) + (k >= 0 && l >= 0 ? sums[k][l] : 0);
						answ = max(sum2,answ);
					}
				}
			}
		}
		
		cout << answ << '\n';
	}
}
