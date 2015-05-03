#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9
#define UNVISITED 0
#define VISITED 1

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vector<vi> AdjList;

ll n;
vi dists, visited;

ll bfs(int u){
	visited.assign(n,UNVISITED);
	vi distsTmp(n,0);
	queue<ll> q;
	q.push(u);
	
	ll last = u;
	while(!q.empty()){
		ll x = q.front(); q.pop();
		last = x;
		visited[x] = VISITED;
		for (int i = 0; i < (int)AdjList[x].size(); i++)
		{
			ll v = AdjList[x][i];
			if(visited[v] == UNVISITED){
				distsTmp[v] = distsTmp[x]+1;
				dists[v] = max(dists[v],distsTmp[v]);
				q.push(v);
			}
		}
	}
	return last;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n){
		AdjList.assign(n, vi());
		
		dists.assign(n, -INF);
		ll k;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			for (int j = 0; j < k; j++)
			{
				ll v;
				cin >> v;
				AdjList[i].push_back(--v);
			}
		}
		
		ll ponta1, ponta2;
		ponta1 = bfs(0);
		ponta2 = bfs(ponta1);
		bfs(ponta2);
		ll melhores = (dists[ponta1]/2) + (dists[ponta1]%2);
		//~ for(int i = 0; i < n; i++) cout << ' ' << dists[i];
		cout << "Best Roots  :";
		for (int i = 0; i < n; i++)
			if(dists[i] == melhores) cout << ' ' << i+1;
		
		cout << "\nWorst Roots :";
		for (int i = 0; i < n; i++)
			if(dists[i] == dists[ponta1]) cout << ' ' << i+1;
		cout << '\n';
	}
}
