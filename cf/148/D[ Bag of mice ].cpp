#include <bits/stdc++.h>

using namespace std;

double memo[1001][1001][3];
bool is_m[1001][1001][3];

double dp(int w, int b, int trn){
	if(w == 0) return 0;
	if(is_m[w][b][trn]) return memo[w][b][trn];
	
	is_m[w][b][trn] = true;
	memo[w][b][trn] = 0;
	
	if(trn == 0){
		memo[w][b][trn] = dp(w-1, b,1)*(((double)w)/(w+b));
		if(b > 0)
			memo[w][b][trn] += dp(w,b-1,1)*(((double)b)/(w+b));
	}
	
	if(trn == 1){ // princess
		memo[w][b][trn] = ((double)w)/(w+b);
		if(b > 0) memo[w][b][trn] += (((double)b)/(w+b))*dp(w,b-1,2);
	}
	if(trn == 2){
		if(b == 0) return memo[w][b][trn] = 0;
		memo[w][b][trn] = dp(w,b-1,0)*(((double)b)/(w+b));
	}
	return memo[w][b][trn];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int w, b;
	while(cin >> w >> b){
		memset(is_m, 0, sizeof is_m);
		cout << fixed << setprecision(10) << dp(w,b,1) << &#39;\n&#39;;
	}
}
