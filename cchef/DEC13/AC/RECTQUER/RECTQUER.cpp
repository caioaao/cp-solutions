#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int,int> ii;

vector<vector<vector<int> > > cumul;

int main(){
	ios_base::sync_with_stdio(false);
	
	int N, Aij, Q;
	ii begin, end;
	while(cin >> N){
		cumul.assign(N, vector<vector<int> >(N, vector<int>(10,0)));
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				for(int k = 0; k < 10; k++) cumul[i][j][k] = (i > 0 ? cumul[i-1][j][k] : 0) + (j > 0 ? cumul[i][j-1][k] : 0) - (i > 0 && j > 0 ? cumul[i-1][j-1][k] : 0);
				cin >> Aij; Aij--;
				cumul[i][j][Aij]++;
			}
		}
		//~ for(int i = 0; i < N; i++){
			//~ for(int j = 0; j < N; j++){
				//~ cout << '[';
				//~ for(int k = 0; k < 10; k++)
					//~ cout << cumul[i][j][k] << ' ';
				//~ cout << "] ";
			//~ }
			//~ cout << endl;
		//~ }
		cin >> Q;
		while(Q--){
			cin >> begin.first >> begin.second >> end.first >> end.second;
			begin.first--; begin.second--; end.first--; end.second--;
			
			int ans = 0,val;
			for(int k = 0; k < 10; k++){
				val = cumul[end.first][end.second][k] - (begin.first > 0 ? cumul[begin.first-1][end.second][k] : 0) - (begin.second > 0 ? cumul[end.first][begin.second-1][k] : 0) + (begin.first > 0 && begin.second > 0 ? cumul[begin.first-1][begin.second-1][k] : 0);
				if(val > 0) ans++;
			}
			cout << ans << '\n';
		}
	}
}
