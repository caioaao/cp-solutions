#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	vi morning, evening;
	int n, d, r;
	cin >> n >> d >> r;
	while(n != 0 || d != 0 || r != 0){
		morning.assign(n,0);
		evening.assign(n,0);
		for(int i = 0; i < n; i++){
			cin >>morning[i];
		}
		for(int i = 0; i < n; i++){
			cin >>evening[i];
		}
		
		sort(morning.begin(), morning.end());
		sort(evening.begin(), evening.end(), greater<int>());
		long long amt = 0;
		for(int i = 0; i < (int)morning.size(); i++){
			amt += max(0,(morning[i]+evening[i]) - d)*r;
		}
		cout << amt << '\n';
		cin >> n >> d >> r;
	}
}
