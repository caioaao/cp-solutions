#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

char grid[101][101], ors[4] = {'N', 'L', 'S', 'O'};
map <char, ii> dor;
map <char, int> oinds;

int main(){
	ios_base::sync_with_stdio(false);
	oinds['N'] = 0;
	oinds['L'] = 1;
	oinds['S'] = 2;
	oinds['O'] = 3;
	
	dor['N'] = make_pair(-1,0);
	dor['L'] = make_pair(0,1);
	dor['S'] = make_pair(1,0);
	dor['O'] = make_pair(0,-1);
	
	int n, m, s, answ;
	ii pos, npos;
	char orientation, move;
	cin >> n >> m >> s;
	while(n != 0 || m != 0 || s != 0){
		answ = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
				if(grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' || grid[i][j] == 'O'){
					pos = make_pair(i,j);
					orientation = grid[i][j];
					grid[i][j] = '.';
				}
			}
		}
		
		for(int i = 0; i < s; i++){
			cin >> move;
			if(move == 'D') orientation = ors[(oinds[orientation] +1)%4];
			else if(move == 'E') orientation = ors[(oinds[orientation] +3)%4];
			else if(move == 'F'){
				npos = make_pair(dor[orientation].first+pos.first,dor[orientation].second+pos.second);
				if(npos.first < n && npos.second < m && npos.first >= 0 && npos.second >= 0 && grid[npos.first][npos.second] != '#'){
					pos.first = npos.first;
					pos.second = npos.second;
					if(grid[pos.first][pos.second] == '*'){
						answ++; grid[pos.first][pos.second] = '.';
					}
				}
		//			cout << pos.first << ',' << pos.second << '\n';
			}
		}
		
		cout << answ << '\n';
		
		cin >> n >> m >> s;
	}
}
