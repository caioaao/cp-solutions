#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 101
#define MAX_K 101

using namespace std;

int dp[MAX_K][MAX_N], N, K;

inline void preprocess(){
	for(int n = 0; n <= 100; n++) dp[1][n] = 1;
	for(int k = 2; k <= 100; k++){
		for(int n = 0; n <= 100; n++){
			dp[k][n] = 0;
			for(int i = 0; i <= n; i++){
				dp[k][n] = (dp[k-1][n-i]%1000000+dp[k][n]%1000000)%1000000;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K;
	preprocess();
	while(N != 0){
		cout << dp[K][N] << '\n';
		
		cin >> N >> K;
	}
}
