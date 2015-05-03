#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

vector<pii> vals;
	
int main(){
	ios_base::sync_with_stdio(false);
	ll T, n, k, s;
	cin >> T;
	while(T--){
		cin >> n >> k >> s;
		vals.assign(n,pii());
		for(ll i = 0; i < n; i++){
			cin >> vals[i].first;
			vals[i].second = i;
		}
		sort(vals.begin(),vals.end(), greater<pii>());
		bool first = true;
		for(ll i = 0; i < n; i++){
			if(!first) cout << ' ';
			first = false;
			cout << vals[i].second + 1;
		}
		cout << '\n';
	}
}
