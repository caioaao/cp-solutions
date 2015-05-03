#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> AdjList;
vi visited, paths, degs;

int main(){
	ios_base::sync_with_stdio(false);
	ll N;
	bool first = true;
	while(cin >> N){
		if(!first) cout << '\n';
		first = false;
		AdjList.assign(N,vi());
		paths.assign(N,0);
		visited.assign(N,0);
		degs.assign(N,0);
		int next, cs;
		for(int i = 0; i < N; i++){
			cin >> cs;
			while(cs--){
				cin >> next;
				AdjList[i].push_back(next);
				degs[next]++;
			}
		}
		queue<int>q1, q;
		q1.push(0);
		paths[0] = 1;
		while(!q1.empty()){
			int u = q1.front(); q1.pop();
			q.push(u);
			for(int i = 0; i < (int)AdjList[u].size(); i++){
				int v = AdjList[u][i];
				if(--degs[v] == 0) {
					q1.push(v);
				}
			}
		}
		while(!q.empty()){
			int u = q.front(); q.pop();
			
			for(int i = 0; i < (int)AdjList[u].size(); i++){
				int v = AdjList[u][i];
				paths[v] += paths[u];
			}
		}
		
		int ans = 0;
		for(int i = 0; i < N; i++){
			if((int)AdjList[i].size() == 0) ans += paths[i];
		}
		cout << ans << '\n';
	}
}
