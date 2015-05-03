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
vector<vector<pii> > seq;
	
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
		ll amt = n/k + (n%k > 0 ? 1 : 0);
		sort(vals.begin(),vals.end());
		seq.assign(amt,vector<pii>());
		for(ll i = 0; i < n; i++){
			seq[i%amt].push_back(vals[i]);
		}
		bool first = true;
		for(ll i = 0; i < (ll)seq.size(); i++)
			for(ll j = 0; j < (ll)seq[i].size(); j++){
				if(!first) cout << ' ';
				first = false;
				cout << seq[i][j].second + 1;
			}
		cout << '\n';
	}
}
