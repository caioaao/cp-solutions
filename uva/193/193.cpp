#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define UNVISITED 0
#define VISITED 1
#define BLACK 0
#define WHITE 1

using namespace std;

typedef vector<int> vi;
map<int,vi> AdjList;
vi cores;
queue<int> available;
vector<set<int> > poss;

int T, n, k, a, b, pMax;

void generate(int id, int amt, set<int> isBlack){
	if(amt+n-id < pMax) return ;
	if(id == n){
		poss.push_back(isBlack);
		pMax = max(pMax,amt);
		return ;
	}
	bool hasBlackNb = false;
	for(int i = 0; i < (int)AdjList[id].size(); i++){
		if(isBlack.count(AdjList[id][i])){
			hasBlackNb = true;
			break;
		}
	}
	generate(id+1, amt, isBlack);
	if(!hasBlackNb){
		set<int> nIsBlack = isBlack;
		nIsBlack.insert(id);
		generate(id+1,amt+1, nIsBlack);
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--){
		pMax = 0;
		cin >> n >> k;
		poss.clear();
		AdjList.clear();
		cores.assign(n, -1);
		for(int i = 0; i < k; i++){
			cin >> a >> b;
			a--; b--;
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		
		int  pAmt = 0, pI;
		
		generate(0, 0,set<int>());
		for(int i = 0; i < (int)poss.size(); i++){
			if((int)poss[i].size() > pAmt){
				pAmt = poss[i].size();
				pI = i;
			}
		}
		cout << pAmt << '\n';
		bool first = true;
		for(set<int>::iterator it = poss[pI].begin(); it != poss[pI].end(); ++it){
			if(!first) cout << ' ';
			first = false;
			cout << (*it)+1;
		}
		cout << '\n';
		
	}
}
