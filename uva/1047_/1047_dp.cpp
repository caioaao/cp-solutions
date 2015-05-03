#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_T 21
#define MAX_CA 11
#define INF 1e9

using namespace std;

int T[MAX_T], n, na, C[MAX_CA], tca, t_tca, m;
map<int, vector<int> > ca;

int nxt[MAX_T][MAX_T];
map <int, map<int, map<int, map<int, int> > > > memo;

int amt(int id, int bitmask, int avail, int lastId){
	if(memo[bitmask][avail][lastId].count(id)) return memo[bitmask][avail][lastId][id];
	if(avail == 0) return 0;
	if(id > n) return 0;
	if(avail > n-id+1) return 0;
	int getting = T[id], nbitmask = bitmask;
	for(int i = 0; i < (int)ca[id].size(); i++){
		if((bitmask & (1<< ca[id][i])) == 0) nbitmask |= (1<< ca[id][i]);
		else getting -= C[ca[id][i]];
	}
	int ansGetting = getting+amt(id+1,nbitmask,avail-1, id), ansNgetting = amt(id+1,bitmask,avail, lastId);
	if(ansGetting >= ansNgetting){
		nxt[avail][lastId] = id;
		return (memo[bitmask][avail][lastId][id] = ansGetting);
	}
	return (memo[bitmask][avail][lastId][id] = ansNgetting);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int caso = 1;
	cin >> n >> na;
	while(n!=0 && na!=0){
		memset(nxt, 0, sizeof nxt);	
		memo.clear();
		cout << "Case Number  " << caso++ << '\n';
		ca.clear();
		
		for(int i = 1; i <= n; i++){
			cin >> T[i];
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> tca;
			for(int j = 0; j < tca; j++){
				cin >> t_tca;
				ca[t_tca].push_back(i);
			}
			cin >> C[i];
		}
		int used = 0;
		
		cout << "Number of Customers: " << amt(1,used,na, 0) << "\nLocations recommended:";
		int avail = na, nind = nxt[avail][0];
		while(avail > 0){
			cout << ' ' << nind;
			nind = nxt[--avail][nind];
		}
		cout << "\n\n";
		
		
		cin >> n >> na;
	}
}
