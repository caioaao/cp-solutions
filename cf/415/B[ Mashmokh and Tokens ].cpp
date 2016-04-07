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

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pii;


int main(){
	ios_base::sync_with_stdio(false);
	ll n, a, b, x, s, k;
	while(cin >> n >> a >> b){
		bool first = true;
		for(ll i = 0; i < n; i++){
			if(!first) cout << &#39; &#39;;
			first = false;
			cin >> x;
			if((x*a)<b){
				 cout << x;
				 continue;
			 }
			s = x * a; k = s/b;
			//~ cout << &#39;;&#39; << k << endl;
			cout << (s -(b*k))/a;
		}
		cout << &#39;\n&#39;;
	}
}
