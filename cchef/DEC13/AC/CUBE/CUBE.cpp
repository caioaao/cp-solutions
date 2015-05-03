#include <iostream>
#include <cstring>
#include <cmath>

#define MAX_N 45

using namespace std;

int cube[MAX_N][MAX_N][MAX_N];
char cube1[MAX_N][MAX_N][MAX_N];

int memo[MAX_N][MAX_N][MAX_N][MAX_N], cumu[MAX_N][MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);
	int T, N;
	long long p;
	cin >> T;
	while(T--){
		cin >> N >> p;
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				for(int k = 0; k < N; k++)
					cin >> cube1[i][j][k];

		char c;
		memset(cumu, 0, sizeof cumu);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				for(int k = 0; k < N; k++){
					cin >> c;
					cube[i][j][k] = (c == cube1[i][j][k]);
					cumu[i][j][k] = cube[i][j][k] + (i > 0 ? cumu[i-1][j][k] : 0) + (j > 0 ? cumu[i][j-1][k] : 0) + (k > 0 ? cumu[i][j][k-1] : 0) -
					 (i > 0 && j > 0 ? cumu[i-1][j-1][k] : 0) - (i > 0 && k > 0 ? cumu[i-1][j][k-1] : 0) - (j > 0 && k > 0 ? cumu[i][j-1][k-1] : 0) +
					  (i > 0 && j > 0 && k > 0 ? cumu[i-1][j-1][k-1] : 0);
				}
				
		long long amt, ponto;
		for(int n = N-1; n >= 0; n--){
			amt = 0;
			for(int i = 0; i+n < N; i++)
				for(int j = 0; j+n < N; j++)
					for(int k = 0; k+n < N; k++){
						ponto = cumu[i+n][j+n][k+n]
								- (i > 0 ? cumu[i-1][j+n][k+n] : 0 ) - (j > 0 ? cumu[i+n][j-1][k+n] : 0) - (k > 0 ? cumu[i+n][j+n][k-1] : 0)
								+ (i > 0 && j > 0 ? cumu[i-1][j-1][k+n] : 0 ) + (i > 0 && k > 0 ? cumu[i-1][j+n][k-1] : 0 ) + (j > 0 && k > 0 ? cumu[i+n][j-1][k-1] : 0 )
								- ( i > 0 && j > 0 && k > 0 ? cumu[i-1][j-1][k-1] : 0 );
						if(ponto*100 >= p*(n+1)*(n+1)*(n+1)) amt++;
					}
			if(amt > 0){
				cout << n+1 << ' ' << amt << '\n';
				break;
			}
		}
		
		//~ for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) for(int k = 0; k < N; k++) cout << cumu[i][j][k] << ' ';
		//~ for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) for(int k = 0; k < N; k++) cout << cube[i][j][k] << ' ';
		//~ cout << endl;
		//~ memset(memo, 0, sizeof memo);
		//~ for(int i = 0; i < N; i++)
			//~ for(int j = 0; j < N; j++)
				//~ for(int k = 0; k < N; k++)
					//~ memo[0][i][j][k] = cube[i][j][k];
//~ 
		//~ for(int n = 1; n < N; n++)
			//~ for(int i = 0; i < N; i++)
				//~ for(int j = 0; j < N; j++)
					//~ for(int k = 0; k < N; k++)
						//~ if(i + n < N && j + n < N && k + n < N)
							//~ memo[n][i][j][k] = (cube[i][j][k] + memo[n-1][i+1][j][k] + memo[n-1][i][j+1][k] + memo[n-1][i][j][k+1] + memo[n-1][i+1][j+1][k] + memo[n-1][i+1][j][k+1] + memo[n-1][i][j+1][k+1]);
		//~ memset(memo, 0, sizeof memo);
			//~ 
//~ 
		//~ long long amt;
		//~ for(int n = N-1; n >= 0; n--){
			//~ amt = 0;
			//~ 
			//~ for(int i = 0; i < N; i++)
				//~ for(int j = 0; j < N; j++)
					//~ for(int k = 0; k < N; k++) if(memo[n][i][j][k]*(long long)100 >= p*n*n*n) amt++;
			//~ if(amt > 0){
				//~ cout << n+1 << ' ' << amt << '\n';
				//~ break;
			//~ }
		//~ }
		if(amt == 0) cout << "-1\n";
	}
}
