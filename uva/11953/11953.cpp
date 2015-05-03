#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <set>

#define MAX_N 110

using namespace std;
typedef pair<int,int> ii;
int N, dx[8] = {-1,-1,-1,0,0,1,1,1}, dy[8] = {-1,0,1,-1,1,-1,0,1};
char grid[MAX_N][MAX_N];
set<ii> pairs;

bool ok(ii p){
	return (p.first >= 0 && p.second >= 0 && p.first < N && p.second < N);
}

void bfs(ii start){
	queue<ii> q;
	q.push(start);
	while(!q.empty()){
		ii p = q.front(); q.pop();
		grid[p.first][p.second] = '.';
		
		for(int i = 0; i < 8; i++){
			ii next = ii(p.first+dx[i],p.second+dy[i]);
			if(ok(next) && (grid[next.first][next.second] == 'x' || grid[next.first][next.second] == '@')){
				q.push(next);
				if(grid[next.first][next.second] == 'x') pairs.erase(next);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int ci = 1; ci <= T; ci++){
		cin >> N;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> grid[i][j];
				
				if(grid[i][j] == 'x') pairs.insert(ii(i,j));
			}
		}
		
		int amt = 0; ii p;
		while(!pairs.empty()){
			p = *(pairs.begin()); pairs.erase(p);
			if(grid[p.first][p.second] == 'x' || grid[p.first][p.second] == '@'){
				bfs(p);
				amt++;
			}
		}
		cout << "Case " << ci << ": " << amt << '\n';
	}
}
