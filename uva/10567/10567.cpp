#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	string linha, query, dummy;
	map<char,vi> pos;
	vi ans;
	vi::iterator ind;
	bool fail;
	int qs, lastI;
	cin >> linha;
	for(int i = 0; i < (int)linha.length(); i++){
		pos[linha[i]].push_back(i);
	}
	cin >> qs;
	while(qs--){
		ans.clear();
		cin >> query;
		lastI = -1;
		fail = false;
		for(int i = 0; i < (int)query.length(); i++){
			ind = lower_bound(pos[query[i]].begin(), pos[query[i]].end(), lastI+1);
			if(ind == pos[query[i]].end()){
				fail = true;
				break;
			}else if(i == 0 || i == (int)query.length()-1){
				ans.push_back(*ind);
			}
			lastI = *ind;
		}
		if(!fail) cout << "Matched " << ans[0] << ' ' << ans[1] << '\n';
		else cout << "Not matched\n";
	}
	
}
