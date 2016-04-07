#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <functional>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <stack>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;

ll memo[10010];
ll c, d, n, m, k;
ll dp(ll left){
	if(left <= 0) return 0;
	if(memo[left] != -1) return memo[left];
	
	return memo[left] = min(dp(left-n)+c,dp(left-1)+d);
}

int main(){
	ios_base::sync_with_stdio(false);
	while(cin >> c >> d >> n >> m >> k){
		memset(memo,-1, sizeof memo);
		cout << dp(n*m-k) << &#39;\n&#39;;
	}
}
