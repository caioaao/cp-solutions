#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;

vector<iii> EdgeList;
vi sets, ans;


int V, E;

inline void unionConstruct(){sets.assign(V,0); for(int i = 0; i < V; i++) sets[i] = i;}
int findSet(int a){ return (sets[a] == a ? a : sets[a] = findSet(sets[a])); }
bool isSameSet(int a, int b){ return findSet(a) == findSet(b);} 
void unionSet(int a, int b){sets[findSet(a)] = findSet(b);}


int main(){
	ios_base::sync_with_stdio(false);
	int x, y, w;
	cin >> V >> E;
	while(V != 0 || E != 0){
		EdgeList.clear(); ans.clear();
		
		for(int i = 0; i < E; i++){
			cin >> x >> y >> w;
			EdgeList.push_back(iii(w,ii(x,y)));
		}
		
		sort(EdgeList.begin(), EdgeList.end());
		unionConstruct();
		for(int i = 0; i < (int)EdgeList.size(); i++){
			int u = EdgeList[i].second.first, v = EdgeList[i].second.second, w = EdgeList[i].first;
			//cout << w << endl;
			if(!isSameSet(u,v)){
				unionSet(u,v);
			}
			else{
				ans.push_back(w);
			}
		}
		
		if(ans.empty()) cout << "forest\n";
		else{
			cout << ans[0];
			for(int i = 1; i < (int)ans.size(); i++)
				cout << ' ' << ans[i];
			cout << '\n';
		}
		
		cin >> V >> E;
	}
}
