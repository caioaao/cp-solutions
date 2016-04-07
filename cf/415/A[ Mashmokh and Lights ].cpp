#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

#define MAX_N 110

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pii;

int main(){
	ios_base::sync_with_stdio(false);
	ll n,m, inds[MAX_N], b;
	bitset<MAX_N> lightsOn;
	while(cin >> n >> m){
		lightsOn.set();
		for(int i = 0; i < m; i++){
			cin >> b;
			b--;
			for(int j = b; j < n; j++){
				if(lightsOn[j]){
					lightsOn.reset(j);
					inds[j] = b;
				}
			}
		}
		bool first = true;
		for(int i = 0; i < n; i++){
			if(!first) cout << &#39; &#39;;
			first = false;
			cout << inds[i]+1;
		}
		cout << &#39;\n&#39;;
	}
}
