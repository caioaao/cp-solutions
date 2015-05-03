#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 101
#define MAX_K 101

using namespace std;

int dp[MAX_N][MAX_K], N, K;

int eval(int val, int k){
	if(val == 0 && k == 0) return 1;
	if(val == 0 || k == 0) return 0;
	if(dp[val][k] == -1){
		dp[val][k] = 0;
		for(int i = 0; i <= val; i++){
			dp[val][k] += eval(val-i,k-1)%1000000;
		}
		
	}
	return dp[val][k]%=1000000;
}


int main(){
	ios_base::sync_with_stdio(false);
	memset(dp,-1,sizeof dp);
	
	cin >> N >> K;
	while(N != 0){
		cout << eval(N,K) << '\n';
		
		cin >> N >> K;
	}
}
