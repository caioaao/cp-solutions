#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX_N 16

using namespace std;
typedef long long ll;

int pos[MAX_N], N;
ll memo[MAX_N][MAX_N];

ll dp(int col, int lastCol){
	if(col == N) return 1;
	if(memo[col][lastCol] != -1) return memo[col][lastCol];
	if(pos[col] != -1){
		if(pos[col] >= lastCol -1 && pos[col] <= lastCol+1){
			return memo[col][lastCol] = 0;
		}
		return memo[col][lastCol] = dp(col+1,pos[col]);
	}
	memo[col][lastCol] = 0;
	for(int i = 0; i < N; i++){
		if(i >= lastCol - 1 && i <= lastCol+1) continue;
		memo[col][lastCol] += dp(col+1, i);
	}
	return memo[col][lastCol];
}

int main(){
	string s;
	while(cin >> s){
		N = s.length();
		memset(memo, -1, sizeof memo);
		for(int i = 0; i < N; i++){
			switch(s[i]){
				case '?':
					pos[i] = -1;
				break;
				case 'A':
					pos[i] = 9;
				break;
				case 'B':
					pos[i] = 10;
				break;
				case 'C':
					pos[i] = 11;
				break;
				case 'D':
					pos[i] = 12;
				break;
				case 'E':
					pos[i] = 13;
				break;
				case 'F':
					pos[i] = 14;
				break;
				default:
					pos[i] = s[i]-'0'-1;
			}
		}
		ll ans = 0;
		if(pos[0] == -1){
			for(int i = 0; i < N; i++)
				ans += dp(1,i);
		}
		else
			ans = dp(1,pos[0]);
		cout << ans << '\n';
	}
}
