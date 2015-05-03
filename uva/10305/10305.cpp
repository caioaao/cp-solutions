#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>

#define UNVISITED 1
#define VISITED 2
#define EXPLORED 3

using namespace std;
typedef vector<int> vi;
typedef map<int, vi > mvi;

mvi AdjList;
vector<int> NodeStat;
stack<int> ordem;

void dfs(int node){
	if(NodeStat[node] != UNVISITED) return;
	NodeStat[node] = VISITED;
	for(vi::iterator it = AdjList[node].begin(); it != AdjList[node].end(); ++it){
		dfs(*it);
	}
	ordem.push(node);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, a, b;
	
	cin >> n >> m;
	while(n != 0 || m!= 0){
		AdjList.clear();
		NodeStat.assign(n+1,UNVISITED);
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			AdjList[a].push_back(b);
		}
		
		for(int i = 1; i <= n; i++){
			if(NodeStat[i] != UNVISITED) continue;
			
			dfs(i);
		}
		
		cout << ordem.top(); ordem.pop();
		
		while(!ordem.empty()) cout << ' ' << ordem.top(), ordem.pop();
		cout << '\n';
		
		cin >> n >> m;
	}
}
