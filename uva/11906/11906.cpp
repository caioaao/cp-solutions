#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_D 105
#define WATER 1
#define VISITED 2

using namespace std;
typedef pair<int,int> ii;

int R,C,M,N, grid[MAX_D][MAX_D], checked[MAX_D][MAX_D], W;

int ok(ii point){
	return (point.first >= 0 && point.second >= 0 && point.first < R && point.second < C);
}

int main(){
	ios_base::sync_with_stdio(false);
	int T, x, y;
	cin >> T;
	queue <ii> q;
	for(int ci = 1; ci <= T; ci++){
		cout << "Case " << ci << ": ";
		cin >> R >> C>> M >> N;
		cin >> W;
		int dMM0[4] = {0,0,N,-N}, dNM0[4] =  {N,-N,0,0}, dMN[4] = {-M, -M, M, M}, dNM[4] = {-N,N,-N,N},  dMN0[4] = {M,-M,0,0}, dNN0[4] =  {0,0, M,-M};
		int dMok[8] = {M,M,-M,-M,N,N,-N,-N}, dNok[8] = {N,-N, N, -N, M, -M, M, -M};
		
		memset(grid, 0, sizeof grid);
		for(int i = 0; i < W; i++){
			cin >> x >> y;
			grid[x][y] = WATER;
		}
		int evens = 0, odds = 0;
		q.push(ii(0,0));
		int *dM, *dN, size;
		if(M == N){dM = dMN; dN = dNM;size = 4;}
		else if(M == 0){dM = dMM0; dN = dNM0;size = 4;}
		else if(N == 0){dM = dMN0; dN = dNN0;size = 4;}
		else {dM = dMok; dN = dNok;size = 8;}
		while(!q.empty()){
			ii p = q.front(); q.pop();
			if(grid[p.first][p.second] == VISITED || grid[p.first][p.second] == WATER) continue;
			grid[p.first][p.second] = VISITED;
			memset(checked, -1, sizeof checked);
			int ki = 0;
			for(int i = 0; i < size; i++){
				ii next = ii(p.first+dM[i],p.second+dN[i]);
			//	cout << next.first << ',' << next.second << endl;
				if(ok(next)){
					if(grid[next.first][next.second] != WATER){
						if(checked[next.first][next.second] < 0) {
							checked[next.first][next.second] = 1;
							ki++;
						}
						if(grid[next.first][next.second] != VISITED) q.push(next);
					}
				}
			}
			if(ki%2 == 0) evens++;
			else odds++;
		}
		
		cout << evens << ' ' << odds << '\n';
	}
}
