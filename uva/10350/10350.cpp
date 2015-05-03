#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define INF 1e7
#define MAX_N 130
#define MAX_M 20

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

ll grid[MAX_N][MAX_M], memo[MAX_N*MAX_M];
vector<vector<ii> > AdjList;

int N, M;

ll dp(int u){
	if(memo[u] != -1) return memo[u];
	if((int)AdjList[u].size() == 0) return memo[u] = 0;
	
	memo[u] = INF;
	for(int i = 0; i < (int)AdjList[u].size(); i++){
		ii v = AdjList[u][i];
		memo[u] = min(memo[u], dp(v.first) + v.second + 2);
	}
	return memo[u];
}

int main(){
	ios_base::sync_with_stdio(false);
	string name;
	while(cin >> name){
		int d;
		cin >> N >> M;
		AdjList.assign(N*M, vector<ii>());
		memset(memo, -1, sizeof memo);
		
		for(int f = 0, ind = 0; f < N; f++){
			for(int i = 0; i < M; i++){
				grid[f][i] = ind++;
			}
		}
		for(int f = 0, ind = 0; f < N-1; f++){
			for(int i = 0; i < M; i++){
				for(int j = 0; j < M; j++){
					cin >> d;
					//~ cout << d << ' ';
					AdjList[ind].push_back(ii(grid[f+1][j],d));
				}
				ind++;
			}
			//~ cout << endl;
		}
		ll ans = INF;
		for(int i = 0; i < M; i++){
			ans = min(ans, dp(grid[0][i]));
		}
		cout << name << '\n' << ans << '\n';
	}
}
