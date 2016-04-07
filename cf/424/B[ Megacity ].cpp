#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>


using namespace std;

typedef long long ll;

ll n, s;
typedef pair<ll,ll> city;

vector<city> cities;

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> s){
		int x, y;
		cities.assign(n, city());
		
		for(int i = 0; i < n; i++){
			cin >> x >> y >> cities[i].second;
			cities[i].first = x*x+y*y;
		}
		
		if(s >= 1000000){
			cout << "0\n";
			continue;
		} 
		
		sort(cities.begin(), cities.end());
		ll popSum = s;
		for(int i = 0; i < n; i++){
			popSum += cities[i].second;
			if(popSum >= 1000000){
				cout << fixed << setprecision(7) << sqrt(cities[i].first) << &#39;\n&#39;;
				break;
			}
		}
		if(popSum <1000000) cout << "-1\n";
	}
}
