#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>

#define MAX_N 10001
#define INF 1e9

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int grid[10][MAX_N], N, dy[3] = {-1,0,1}, df[3] = {20, 30, 60};
vector<vi> dp;


int bfs(int x, int y){
	if(x == N){
		if(y == 0) return 0;
		else return INF;
	}
	if((x!=0 && y == 0)  || N-x < y) return INF;
	if(dp[y][x] != -1) return dp[y][x];
	
	dp[y][x] = INF;
	for(int i = 0; i < 3; i++){
		if(y +dy[i] >= 0 && y+dy[i] < 10)
			dp[y][x] = min(dp[y][x], bfs(x+1, y+dy[i])+df[i]-grid[y][x]);
	}
	return dp[y][x];
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> N;
		N /= 100;
		
		dp.assign(15, vi(N+5,-1));
		
		for(int i = 9; i >=0; i--){
			for(int j = 0; j < N; j++){
				cin >> grid[i][j];
			}
		}
		cout <<bfs(0,0) << "\n\n";
	}
}
