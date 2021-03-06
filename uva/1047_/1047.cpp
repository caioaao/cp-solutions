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
int ca[MAX_T+1][MAX_T+1];
int ca_sz[MAX_T+1];

int nxt[MAX_T][MAX_T];


int amt(int id, int bitmask, int avail, int lastId){
	if(avail == 0) return 0;
	if(id > n) return 0;
	if(avail > n-id+1) return 0;
	int getting = T[id], nbitmask = bitmask;
	for(int i = 0; i < ca_sz[id]; i++){
		if((bitmask & (1<< ca[id][i])) == 0) nbitmask |= (1<< ca[id][i]);
		else getting -= C[ca[id][i]];
	}
	int ansGetting = getting+amt(id+1,nbitmask,avail-1, id), ansNgetting = amt(id+1,bitmask,avail, lastId);
	if(ansGetting >= ansNgetting){
		nxt[avail][lastId] = id;
		return ansGetting;
	}
	return ansNgetting;

}

int main(){
	ios_base::sync_with_stdio(false);
	int caso = 1;
	cin >> n >> na;
	while(n!=0 && na!=0){
		memset(nxt, 0, sizeof nxt);
		cout << "Case Number  " << caso++ << '\n';
                memset(ca_sz, 0, sizeof ca_sz);

		for(int i = 1; i <= n; i++){
			cin >> T[i];
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> tca;
			for(int j = 0; j < tca; j++){
				cin >> t_tca;
				ca[t_tca][ca_sz[t_tca]++] = i;
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
