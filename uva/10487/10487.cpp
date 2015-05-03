#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>

#define MAX_N 1001

using namespace std;

typedef pair<int,int> ii;

typedef long long ll;

ll l[MAX_N];
vector<ll> sums;
map<ll, bool> used;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll n, m, x, ans;
	
	cin >> n;
	
	int caso = 1;
	
	while(n != 0){
		used.clear();
		sums.clear();
		
		cout << "Case " << caso << ":\n";
		for(int i = 0; i < n; i++){
			cin >> l[i];
			if(!used.count(l[i])){
				for(int j = 0; j < i; j++){
					if(l[i] != l[j])
						sums.push_back(l[i]+l[j]);
				}
				used[l[i]] = true;
			}
		}
		sort(sums.begin(), sums.end());
		cin >> m;
		vector<ll>::iterator it;
		bool first2 = true;
		for(int i = 0; i < m; i++){
			if(!first2) cout << '\n';
			first2 = false;
			cin >> x;
			it = lower_bound(sums.begin(),sums.end(),x);
			if(*it == x)	ans = x;
			else if(it == sums.end()) ans = *(sums.end()-1);
			else if(it == sums.begin()) ans = *it;
			else if(abs((*(it-1))-x) > abs((*it)-x)) ans = *it;
			else ans = *(it-1);
			cout << "Closest sum to " << x << " is " << ans << ".";
		}
		caso++;
		cout << '\n';
		
		cin >> n;
	}
}
