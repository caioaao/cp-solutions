#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll num;
	while(cin >> num){
		if(num < 0) break;
		
		ll maxP;
		bool poss = false;
		for(int p = 2; p < sqrt(num)+1; p++){
			ll left = num, i = 0;
			for(; i < p; i++){
				if((left-1)%p == 0){
					left -= (left-1)/p + 1;
				}
				else{
					break;
				}
			}
			if(i == p && left % p == 0){
				maxP = p;
				poss = true;
			}
		}
		if(!poss) cout << num << " coconuts, no solution\n";
		else cout << num << " coconuts, " << maxP << " people and 1 monkey\n";
	}
}
