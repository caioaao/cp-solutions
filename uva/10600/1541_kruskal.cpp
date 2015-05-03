#include <iostream>
#include <queue>
#include <map>
#include <bitset>
#include <algorithm>

#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef long long int lli;
typedef vector<int> vi;

vi pset;

void initSet(int N){
	pset.clear();
	pset.assign(N,0);
	for(int i = 0; i < N; i++) pset[i] = i;
}
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); } 
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }

int main(){
	int T,N,M, Ai, Bi, Ci;

	cin >>T;

	for(int count = 0; count < T; count++){
		cin >> N >> M;
		vector<bool> canGet, used;
		vector<pair<int,ii> > EdgeList;

		for(int count2 = 0; count2 < M; count2++){
			cin >> Ai >> Bi >> Ci;
			EdgeList.push_back(make_pair(Ci, ii(Ai-1, Bi-1)));
			canGet.push_back(true);
			used.push_back(false);
		}
		sort(EdgeList.begin(), EdgeList.end());
		
		lli mst_cost = 0; initSet(N);
		for(int i = 0; i < M; i++){
			pair<int, ii> front = EdgeList[i];
			if(!isSameSet(front.second.first, front.second.second)){
				used[i] = true;
				mst_cost += front.first;
				unionSet(front.second.first, front.second.second);
			}
		}
		cout << mst_cost << ' ';

		mst_cost = INF;
		lli mst_cost_helper;
		for(int j = 0; j < M; j++){
			if(!used[j]) continue;

			mst_cost_helper = 0;

			initSet(N);
			int n_schools = 0;
			for(int i = 0; i < M; i++){
				if(i == j) continue;
				pair<int, ii> front = EdgeList[i];
				if(!isSameSet(front.second.first, front.second.second)){
					n_schools++;
					mst_cost_helper += front.first;
					unionSet(front.second.first, front.second.second);
				}
			}
			//cout << "Edge removida: " << j << ", custo: " << mst_cost_helper << endl;
			if(n_schools == N-1)
				mst_cost = min(mst_cost_helper, mst_cost);
		}
		cout << mst_cost << endl;
	}
}
