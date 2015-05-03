#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	ll t, n, num;
	map <ll, int> snowflakes;
	cin >> t;
	while(t--){
		snowflakes.clear();
		cin >> n;
		ll begin = 1, big = 0, size = 0;
		
		for(ll i = 1; i <= n; i++){
			cin >> num;
			if(snowflakes[num] >= begin){
				size = i - begin;
				big = max(size, big);
				//cout << big << ',' << i << ',' << begin << endl;
				begin = snowflakes[num]+1;
			}
			snowflakes[num] = i;
		}
		size = n - begin+1;
		big = max(size, big);
		//for(map<ll, int>::const_iterator i = snowflakes.begin(); i != snowflakes.end(); ++i){
			//	cout << '[' << i->first << ' ' << i->second << ']';
		//}
		 cout << big << '\n';
	}
}
