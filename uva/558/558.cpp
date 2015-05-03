#include <iostream>
#include <vector>
#include <map>

#define INF 1e9

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, vii> mvii;

int main(){
	ios_base::sync_with_stdio(false);
	
	int t, n, m, x, y, z;
	mvii AdjList;
	vi dist;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		AdjList.clear();
		dist.assign(n, INF);
		for(int i = 0; i < m; i++){
			cin >> x >> y >> z;
			AdjList[x].push_back(ii(y,z));
		}
		
		dist[0] = 0;
		for(int i = 0; i < n; i++){
			for(mvii::const_iterator u = AdjList.begin(); u != AdjList.end(); ++u){
				for(int j = 0; j < (int)u->second.size(); j++){
					ii v = u->second[j];
					dist[v.first] = min(dist[v.first], dist[u->first] + v.second);
				}
			}
		}
		
		bool possible = false;
		for(mvii::const_iterator u = AdjList.begin(); u != AdjList.end(); ++u){
			for(int j = 0; j < (int)u->second.size(); j++){
				ii v = u->second[j];
				if(dist[v.first] > dist[u->first] + v.second){
					possible = true;
					break;
				}
			}
		}
		
		if(!possible) cout << "not ";
		cout << "possible\n";
	}
}
