#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
	int n;
	map<int, int> weights, pot;
	int maior;
	while( cin >> n ){
		weights.clear(); pot.clear();
		int corners = pow(2,n);
		for(int i = 0; i < corners; i++){
			cin >> weights[i];
		}
		
		maior = 0;
		int corn;
		for(int i = 0; i < corners; i++){
			pot[i] = 0;
			for(int k = 0; k < n; k++){
				if((i & (1<<k)) == 0)
					corn = i | (1 << k);
				else
					corn = i & ~(1 << k);
				pot[i] += weights[corn];
			}
		}
		for(int i = 0; i < corners; i++){
			for(int k = 0; k < n; k++){
				if((i & (1<<k)) == 0){
					corn = i | (1 << k);
					maior = max(maior, pot[i]+pot[corn]);
				}
			}
		}
		cout << maior << '\n';
	}
}
