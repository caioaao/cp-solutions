#include <iostream>
#include <vector>
#include <map>
#include <algorithm>



using namespace std;
typedef long long ll;
typedef pair<ll,ll> point;

vector<point> s;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll T, n, k, p, r, l;
	cin >> T;
	while(T--){
		cin >> n >> k >> p;
		s.assign(k,point());
		for(ll i = 0; i < k; i++){
			cin >> s[i].first >> s[i].second;
			
			if(s[i].first > s[i].second){
				s.push_back(point(s[i].first-n, s[i].second));
				s[i].second += n;
			}
		}
		
		bool ok = true;
		
		//~ for(ll i = 0; i < (ll)s.size(); i++) cout << 'c' << s[i].first << '-' << s[i].second << endl;
		
		for(ll i = 0; i < p; i++){
			cin >> l >> r;
			//~ cout << 'b' << l << '-' << r << endl;
			for(ll j = 0; j < (ll)s.size(); j++){
				if(!ok) break;
				//~ cout << l << '-' << r << ':' << s[j].first << '-' << s[j].second << endl;
				if((l > s[j].first && l <= s[j].second) || (r >= s[j].first && r < s[j].second)) ok = false;
			}
		}
		
		if(ok) cout << "Yes\n";
		else cout << "No\n";
	}
}
