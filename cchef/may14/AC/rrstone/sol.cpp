#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll nums[100010];

int main(){
	ios_base::sync_with_stdio(false);
	
	ll n, k;
	while(cin >> n >> k){
		ll maior = -3e9, menor = 3e9;
		for(int i = 0; i < n; i++){
			cin >> nums[i];
			maior = max(maior,nums[i]);
			menor = min(menor, nums[i]);
		}
		if(k == 0){
			cout << nums[0];
			for(int i = 1; i < n; i++) cout << ' ' << nums[i];
			cout << '\n';
			continue;
		}
		k%=2;
		if(k == 0) cout << nums[0]-menor;
		else cout << maior - nums[0];
		for(int i = 1; i < n; i++){
			if(!k) cout << ' ' << nums[i]-menor;
			else cout << ' ' << maior - nums[i];
		}
		cout << '\n';
	}
}
