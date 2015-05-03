#include <iostream>
#include <queue>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef long long int lli;

bitset <100> taken;
priority_queue<ii> pq;
vector<vector<ii> > AdjList;

void process(int vtx){
	taken.set(vtx);

	for(int j = 0; j < (int)AdjList[vtx].size(); j++){
		ii v = AdjList[vtx][j];
		if(!taken[v.first]) pq.push(ii(-v.second,-v.first));
	}
}

int main(){
	int T,N,M, Ai, Bi, Ci;

	cin >>T;

	for(int count = 0; count < T; count++){
		cin >> N >> M;

		taken.reset();
		AdjList.clear();
		AdjList.resize(N);

		for(int count2 = 0; count < M; count++){
			cin >> Ai >> Bi >> Ci;
			AdjList[Ai-1].push_back(make_pair(Bi-1, Ci));
		}

		process(0);
		lli mst_cost = 0;
		int u,w;
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			u = -front.second; w = -front.first;
			if(!taken[u])
				mst_cost += w, process(u);
		}
		cout << mst_cost << endl;
		
	}
}
