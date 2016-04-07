#include <iostream>

using namespace std;

int mat[101][101];
int R, C;

bool isEq(int r1, int r2){
	for(int i = 0; i < C; i++) if(mat[r1][i] != mat[r2][i]) return false;
	return true;
}

int solve(int n){
	if(n % 2 == 1) return n;
	
	for(int i = 0; i < n; i++){
		if(!isEq(i, n-i-1)) return n;
	}
	return solve(n/2);
}

int main(){
	ios_base::sync_with_stdio(false);
	while(cin >> R >> C){
		for(int i =0 ; i < R; i++)
			for(int j = 0; j < C; j++)
				cin >> mat[i][j];
		cout << solve(R) << &#39;\n&#39;;
	}
}
