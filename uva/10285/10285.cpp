#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>

#define MAX_S 110

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long ll;

int R, C;
ll memo[MAX_S][MAX_S], heights[MAX_S][MAX_S];
int dR[4] = {0,0,1,-1};
int dC[4] = {1,-1,0,0};

bool possible(ii u){
	if(u.first >= 0 && u.second >= 0 && u.first < R && u.second < C)
		return true;
	return false;
}

ll dp(ii u){
	if(memo[u.first][u.second] != -1) return memo[u.first][u.second];
	memo[u.first][u.second] = 1;
	for(int i = 0; i < 4; i++){
		ii v(u.first+dR[i], u.second+dC[i]);
		if(possible(v) && heights[u.first][u.second] > heights[v.first][v.second])
			memo[u.first][u.second] = max(memo[u.first][u.second], dp(v)+1);
	}
	return memo[u.first][u.second];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		memset(memo,-1, sizeof memo);
		memset(heights,-1, sizeof heights);
		string s;
		cin >> s >> R >> C;
		priority_queue<iii>pq;
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				cin >> heights[i][j];
				pq.push(iii(heights[i][j],ii(i,j)));
			}
		}
		ll ans = 0;
		while(!pq.empty()){
			ii u = pq.top().second;pq.pop();
			if(memo[u.first][u.second] == -1){
				ans = max(ans, dp(u));
			}
		}
		cout << s << ": " << ans << '\n';
	}
}
