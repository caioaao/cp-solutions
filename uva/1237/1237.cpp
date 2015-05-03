#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define MAX_DB 10001

using namespace std;

typedef pair<int,string> is;
typedef map<int, is> miis;

miis db;
int main(){
	ios_base::sync_with_stdio(false);
	
	int T, D, Q, P, l, h;
	string s;
	cin >> T;
	bool first = true;
	while(T--){
		if(!first) cout << '\n';
		first = false;
		db.clear();
		cin >> D;
		
		for(int i = 0; i < D; i++){
			cin >> s >> l >> h;
			db[l] = pair<int,string>(h,s);
		}
		cin >> Q;
		while(Q--){
			cin >> P;
			string ans;
			bool found = false;
			for(miis::const_iterator it = db.begin(); it != db.end(); ++it){
				if(it->first <= P && it->second.first >= P){
					if(!found){
						found = true;
						ans = it->second.second;
					}
					else{
						found = false; break;
					}
				}
				if(it->first > P) break;
			}
			if(!found) cout << "UNDETERMINED\n";
			else cout << ans << '\n';
		}
	}
}
