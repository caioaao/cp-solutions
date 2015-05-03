#include <iostream>
#include <vector>

#define VISITED 1
#define UNVISITED -1

using namespace std;
typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num,colors;
int V;

bool checkBip(int id, int c1, int c2){
	if(dfs_num[id] == VISITED){
		if(colors[id] == c2) return false;
		return true;
	}
	dfs_num[id] = VISITED;
	colors[id] = c1;
	for(int i = 0; i < (int)AdjList[id].size(); i++){
		if(!checkBip(AdjList[id][i],c2,c1)) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> V;
	while(V != 0){
		AdjList.assign(V, vi());
		cin >> a >> b;
		while(a != 0 && b != 0){
			a--; b--;
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
			cin >> a >> b;
		}
		dfs_num.assign(V,UNVISITED);
		colors.assign(V,-1);
		for(int i = 0; i < V; i++){
			if(dfs_num[i] == UNVISITED && !checkBip(i, 1, 0)){
				cout << "NO\n"; goto fail;
			}
		}
		cout << "YES\n";
		fail:
		cin >> V;
	}
}
