#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(false);
	int n, x;
	ll sums, mins,answ;
	cin >> n;
	while(n != 0){
		cin >> x;
		sums = x; mins = x;
		answ = x;
		
		for(int i = 1; i < n; i++){
			cin >> x;
			sums+=x;
			mins = min(mins,sums);
			answ = max(sums-mins,answ);
		}
		
		if(answ > 0) cout << "The maximum winning streak is " << answ << ".\n";
		else cout << "Losing streak.\n";
		
		cin >> n;
	}
}
