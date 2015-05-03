#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;


int V, E, nSets;
vector<iii> EdgeList;
vi sets;

void unionConstruct(){sets.assign(V,0); for(int i = 0; i < V; i++) sets[i] = i; nSets = V;}
int findSet(int a){return (sets[a] == a ? a : sets[a] = findSet(sets[a]));}
bool isSameSet(int a, int b){ return findSet(a) == findSet(b);}
void unionSet(int a, int b){
	if(!isSameSet(a,b)){
		nSets--;
		sets[findSet(a)] = findSet(b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	int x, y, z;
	while(V != 0){
		EdgeList.clear();
		int tot = 0;
		for(int i = 0; i < E; i++){
			cin >> x >> y >> z;
			tot+= z;
			EdgeList.push_back(iii(z,ii(x, y)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		unionConstruct();
		int ans = 0;
		for(int i = 0; i < E && nSets > 1; i++){
			iii p = EdgeList[i];
			if(!isSameSet(p.second.first,p.second.second)){
				unionSet(p.second.first,p.second.second);
				ans += p.first;
			}
		}
		
		cout << tot-ans << '\n';
		cin >> V >> E;
	}
}
