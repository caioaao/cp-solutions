#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	map<char,int> price;
	
	ll T, k, ans, p, m;
	char c;
	string line;
	stringstream buff;
	cin >> T;
	
	while(T--){
		price.clear();
		ans = 0;
		cin >> k;
		for(ll i = 0; i < k; i++){
			cin >> c >> p;
			price[c] = p;
		}
		cin >> m;
		getline(cin, line);
		for(int i = 0; i < m; i++){
			buff.clear();
			getline(cin, line);
			buff.str(line);
		//	cout << line << endl;
			while(buff >> c){
			//	if(price.count(c)) cout << c << price[c] <<  '\n';
				if(price.count(c))
					ans += price[c];
			}
		}
		cout << fixed << setprecision(2) << ans/100. << "$\n";
	}
}
