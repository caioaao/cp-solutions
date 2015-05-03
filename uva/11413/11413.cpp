#include <iostream>
#include <algorithm>

#define MAX_N 10000010


using namespace std;
typedef long long ll;


int n, m, x, max_v, high, low, mid;
ll somas[MAX_N];

bool can(int cap){
	int last = 0, conts = 1;
	for(int i = 1; i <= n; i++){
		if(somas[i] - somas[last] > cap){
			last = i-1;
			conts++;
		}
	}
	return (conts <= m);
}

int main(){
	ios_base::sync_with_stdio(false);
	somas[0] = 0;
	while(cin >> n >> m){
		max_v = 0;
		for(int i = 1; i <= n; i++){
			cin >> x;
			somas[i] = somas[i-1]+x;
			max_v = max(max_v,x);
		}
		
		if(m >= n) {
			cout << max_v << '\n';
			continue;
		}
		if(m == 1){
			cout << somas[n] << '\n';
			continue;
		}
		
		high = somas[n]; low = max_v;
		
		while(high-low > 1){
			mid = (high+low)/2;

			if(can(mid))
				high = mid;
			else
				low = mid;
		}
		cout << (can(low) ? low : high) << '\n';
	}
}

