#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define ABRE_BOY 0
#define ABRE_CHEF 1
#define FECHA_CHEF 2
#define FECHA_BOY 3


using namespace std;
typedef long long ll;
typedef pair<ll,ll> point;

bool dentroBoy, dentroChef;

vector<point> s;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll T, n, k, p, r, l, nps;
	cin >> T;
	while(T--){
		cin >> n >> k >> p;
		ll ind = 0;
		nps = (k+p)*2;
		s.assign(nps,point());
		for(ll i = 0; i < k; i++){
			cin >> l >> r;
			if(l > r){
				l -= n;
				s.push_back(point(l, ABRE_CHEF));
				s.push_back(point(r, FECHA_CHEF));
				r += n;
				l+=n;
			}
			s[ind++] = point(l, ABRE_CHEF);
			s[ind++] = point(r, FECHA_CHEF);
		}
		
		for(ll i = 0; i < p; i++){
			cin >> l >> r;
			if(l > r){
				l -= n;
				s.push_back(point(l, ABRE_BOY));
				s.push_back(point(r, FECHA_BOY));
				r += n;
				l+=n;
			}
			s[ind++] = point(l, ABRE_BOY);
			s[ind++] = point(r, FECHA_BOY);
		}
		dentroBoy = dentroChef = false;
		
		sort(s.begin(),s.end());
		bool ok = true;
		for(ll i = 0; i < (ll)s.size(); i++){
			point pt = s[i];
			//~ cout << s[i].first << ':';
			switch(pt.second){
				case ABRE_BOY:
					dentroBoy = true;
					//~ cout << "Abre boy" << endl;
				break;
				case ABRE_CHEF:
					//~ cout << "Abre chef" << endl;
					if(dentroBoy) dentroChef = true;
					else{
						ok = false;
						goto cabo;
					}
				break;
				case FECHA_CHEF:
					//~ cout << "Fecha chef" << endl;
					dentroChef = false;
				break;
				case FECHA_BOY:
					//~ cout << "Fecha boy" << endl;
					if(dentroChef){
						ok = false;
						goto cabo;
					}
					else dentroBoy = false;
			}
		}
		cabo:
		if(ok) cout << "Yes\n";
		else cout << "No\n";
	}
}
