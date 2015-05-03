#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

int n;
string line, combs[10] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
vector<string> lines;
vector<vi > poss;
vector<vector<int > > burned;

bool test(int id){
	if(id == n && !poss[id].empty()) return true;
	if(poss[id].empty()) return false;
	
	int nburned;
	int buit = 0;
	for(vi::iterator it = poss[id].begin(); it != poss[id].end(); ++it, buit++){
		
		bool ok = true;
		nburned = burned[id][buit];
		for(int i = 0; i < 8; i++){
			if(combs[(*it)][i] != lines[id][i]){
				if(lines[id][i] == 'Y'){
					ok = false;
					break;
				}
				else{
					nburned |= 1<< i;;
				}
			}
			else if(lines[id][i] == 'Y' && ((burned[id][buit] &(1 << i))!=0)){
				ok = false;
				break;
			}
			
		}
		if(ok){
			poss[id+1].push_back((*it)-1);
			burned[id+1].push_back(nburned);
		}
	}
	
	return test(id+1);
}
	
int main(){
	cin >> n;
	while(n != 0){
		burned.assign(n+1,vector<int >());
		lines.assign(n,"");
		poss.assign(n+1,vi());
		
		getline(cin, line);
		
		for(int i = 0; i < n; i++){
			getline(cin, lines[i]);
		}
		
		for(int i = 9; i >= n-1; i--){
			poss[0].push_back(i);
			burned[0].push_back(0);
		
		}
		
		if(test(0))
			cout << "MATCH\n";
		else
			cout << "MISMATCH\n";
		
		cin >> n;
	}
	
}
