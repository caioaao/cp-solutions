#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_N 100
#define MAX_K 10
#define FROM_LEFT 0
#define FROM_RIGHT 1
#define FROM_UP 2

using namespace std;
typedef long long ll;

int K, N;

ll memo[MAX_N][MAX_N][MAX_K][3], grid[MAX_N][MAX_N];
bool memoized[MAX_N][MAX_N][MAX_K][3], possible[MAX_N][MAX_N][MAX_K][3];

bool dp(int x, int y, int kLeft, int from){
	if(x == N-1 && y == N-1 && kLeft >= 0 && (kLeft > 0 || grid[x][y] >= 0)){
		memo[x][y][kLeft][from] = grid[x][y];
		return possible[x][y][kLeft][from] = true;
	}
	if(x < 0 || y < 0 || x >= N || y >= N || kLeft < 0) return false;
	if(memoized[x][y][kLeft][from]) return possible[x][y][kLeft][from];
	
	if(grid[x][y] < 0 && kLeft == 0){
		memoized[x][y][kLeft][from] = true;
		return possible[x][y][kLeft][from] = false;
	}
	possible[x][y][kLeft][from] = false;
	memoized[x][y][kLeft][from] = true;
	int nkLeft = kLeft - (grid[x][y] < 0 ? 1 : 0);
	
	if(dp(x+1,y, nkLeft, FROM_UP)){
		memo[x][y][kLeft][from] = memo[x+1][y][nkLeft][FROM_UP]+grid[x][y];
		possible[x][y][kLeft][from] = true;
	}
	if(from != FROM_RIGHT){
		if(dp(x,y+1, nkLeft, FROM_LEFT)){
			if(!possible[x][y][kLeft][from]) memo[x][y][kLeft][from] = memo[x][y+1][nkLeft][FROM_LEFT]+grid[x][y];
			else memo[x][y][kLeft][from] = max(memo[x][y][kLeft][from], memo[x][y+1][nkLeft][FROM_LEFT]+grid[x][y]);
			
			possible[x][y][kLeft][from] = true;
		}
	}
	if(from != FROM_LEFT){
		if(dp(x,y-1, nkLeft, FROM_RIGHT)){
			if(!possible[x][y][kLeft][from]) memo[x][y][kLeft][from] = memo[x][y-1][nkLeft][FROM_RIGHT]+grid[x][y];
			else memo[x][y][kLeft][from] = max(memo[x][y][kLeft][from], memo[x][y-1][nkLeft][FROM_RIGHT]+grid[x][y]);
			
			possible[x][y][kLeft][from] = true;
		}
	}
	return possible[x][y][kLeft][from];
}

int main(){
	ios_base::sync_with_stdio(false);
	int caso = 1;
	while(cin >> N >> K){
		if(N == 0 &&  K == 0) return 0;
		memset(memoized, 0, sizeof memoized);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				cin >> grid[i][j];
		cout << "Case " << caso++ << ": ";
		if(dp(0,0,K, FROM_UP))
			cout << memo[0][0][K][FROM_UP] << '\n';
		else
			cout << "impossible\n";
	}
}
