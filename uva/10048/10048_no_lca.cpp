#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;


int V, E, Q, numSets;

vector<iii> EdgeList;
vector<vector<ii> > AdjList;
vi Ps;

void unionConstruct(){ numSets = V; Ps.assign(V+1,0); for(int i =1; i <= V; i++) Ps[i] = i; }
int unionFind(int a){return (a == Ps[a] ? a : unionFind(Ps[a]));}
bool isSameSet(int a, int b){ return unionFind(a) == unionFind(b); }
void unionSets(int a, int b){
	if(!isSameSet(a,b)){
		numSets--;
		Ps[unionFind(a)] = unionFind(b);
	}
}


int findPath(int a, int b){
	queue<int> q;
	vector<ii> parent(V+1,ii(-1,-1));
	vi visited(V+1, 0);
	
	q.push(a);
	
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(visited[u] == 1) continue;
		visited[u] = 1;
		for(int i = 0; i < (int)AdjList[u].size(); i++){
			ii v = AdjList[u][i];
			if(visited[v.first] != 0) continue;
			parent[v.first] = ii(u, v.second);
			if(v.first == b){
				int ans = -1, curr = v.first;
				while(curr != a){
					ans = max(ans, parent[curr].second);
					curr = parent[curr].first;
				}
				return ans;
			}
			q.push(v.first);
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int a, b, c,caso = 1;
	
	cin >> V >> E >> Q;
	bool first = true;
	while(V != 0){
		if(!first)
			cout << '\n';
		first = false;
		cout << "Case #" << caso++ << '\n';
		EdgeList.clear();
		AdjList.assign(V+1, vector<ii>());
		for(int i = 0; i < E; i++){
			cin >> a >> b >> c;
			EdgeList.push_back(iii(c,ii(a,b)));
		}
		unionConstruct();
		sort(EdgeList.begin(), EdgeList.end());
		for(int i = 0; i < E && numSets > 1; i++){
			int u = EdgeList[i].second.first, v = EdgeList[i].second.second, w = EdgeList[i].first; 
			if(!isSameSet(u,v)){
				unionSets(u,v);
				AdjList[u].push_back(ii(v, w));
				AdjList[v].push_back(ii(u,w));
			}
		}
		
		while(Q--){
			cin >> a >> b;
			int ans = findPath(a,b); 
			if(ans >= 0) cout << ans << '\n';
			else  cout << "no path\n";
		}
		cin >> V >> E >> Q;
	}
}
