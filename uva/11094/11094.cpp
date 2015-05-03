#include <iostream>
#include <map>
#include <vector>

using namespace std;

char mapa[21][21];
int dr[4] = {1,0,-1,0}; // S,E,N,W
int dc[4] = {0,1,0,-1};
map <int, int> conta;

int m, n, x, y;

int floodfill(int r, int c, char c1, char c2){
	if(r >= m || r < 0) return 0;
	c = (c+n)%n;
	if(mapa[r][c] != c1) return 0;
//	cout << (int)c2 << ':' << r << ',' << c << '\n';
	int ans = 1;
	mapa[r][c] = c2;
	for(int d = 0; d < 4; d++) ans+= floodfill(r+dr[d],c+dc[d], c1,c2);
	return ans;
}

int main(){
	while(cin >> m >> n){
		conta.clear();
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >>mapa[i][j];
			}
		}
		
		cin >> x >> y;
		int answ = 0; char land = mapa[x][y];
		
		floodfill(x,y,land, 0);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(mapa[i][j] != land) continue;
				answ = max(answ,floodfill(i,j,land,0));
			}
		}
		
		cout << answ << '\n';
		
	}
}
