#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#define MAX_N 100010

using namespace std;
bool memo[361][361],
	 memoized2[362],
	 memo2[362];

int t, n;
bool dp(int id, int amt, int cLeft){
	if(cLeft < 0)
		return false;
	
	if(memoized2[amt]) return memo2[amt];
	
	memoized2[amt] = true;
	
	if(id == 361){
		if(cLeft == 0)
			return memo2[amt] = true;

		return memo2[amt] = false;
	}
	
	return memo2[amt] = dp(id+1, amt, cLeft) || dp(id+1, amt-1, cLeft-id);
}

void dp2(){
	memset(memo,false,sizeof memo);
	for(int i = 0; i <= 360; i++){
		memo[i][0] = false;
		memo[0][i] = true;
	}
	memo[0][0] = true;
	for(int i = 1; i <= 360; i++){
		for(int j = 1; j <=360; j++){
			for(int k = 1; k <= j; k++){
				if(memo[i-1][j - k] == true){
					memo[i][j] = true;
					break;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> t;
	memset(memoized2, 0, sizeof memoized2);
	dp2();
	dp(1,360,360);
	while(t--){
		cin >> n;
		if(n > 360){
			cout << "n n n\n";
			continue;
		}
		if(360%n == 0) cout << 'y';
		else cout << 'n';
		
		if(memo[n][360])cout << " y";
		else cout << " n";
		
		if(memo2[361-n]) cout << " y\n";
		else cout << " n\n";
	}
}
