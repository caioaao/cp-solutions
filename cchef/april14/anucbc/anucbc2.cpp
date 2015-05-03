#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
 
#define MAX_N 100510
#define MAX_M 110
#define MODP 1000000009
 
using namespace std;
typedef long long ll;
 
ll memo[2*MAX_M][2*MAX_M], n, n2, n3, q, m;
 
ll nums[2*MAX_M][2*MAX_M], nums2[MAX_N], nums3[2*MAX_M], resps[2*MAX_M];
ll facs[MAX_N], facsInv[MAX_N];
 
ll pot(ll a, ll b, ll MOD) {
ll x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD;
		b /= 2;
	}
	return x;
}
 
ll mul_inv(ll a, ll m) {
    return pot(a,m-2,m);
}
 
void calcFacs(){
	facs[0] = 1;
	facsInv[0] = 1;
	for(ll i = 1; i < MAX_N; i++){
		facs[i] = (facs[i-1]*i)%MODP;
		facsInv[i] = (facsInv[i-1]*mul_inv(i,MODP))%MODP;
	}
}

ll combs(ll k, ll els){
	if(k == 0) return 1;
	return (facs[els]*(facsInv[k]*facsInv[els-k])%MODP)%MODP;
}
 
ll dp(ll num, ll resto){
	if(num == m && resto%m == 0) return 1;
	if(num == m) return 0;
	
	if(memo[num+100][resto+100] != -1) return memo[num+100][resto+100];
	
	memo[num+100][resto+100] = 0;
	for(ll i = -m+1; i < m; i++){
		memo[num+100][resto+100] = (memo[num+100][resto+100] + (nums[num+100][i+100]*dp(num+1,(resto+i)%m))%MODP)%MODP;
	}
 
	return memo[num+100][resto+100] = memo[num+100][resto+100]%MODP;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	calcFacs();
	while(T--){
		n3 = 0;
		cin >> n2 >> q;
		
		for(int i = 0; i < n2; i++)
			cin >> nums2[i];
		memset(resps,-1,sizeof resps);
		while(q--){
			cin >> m;
			if(resps[m] > -1){
				cout << resps[m] << '\n';
				continue;
			}
			memset(nums3, 0, sizeof nums3);
			memset(memo,-1,sizeof memo);
			
			for(ll i = 0; i < n2; i++){
				nums3[(nums2[i]%m) + 100]++;
			}
			
			ll r;
			
			memset(nums, 0, sizeof nums);
			
			for(ll i = -m+1; i < m; i++){
				for(ll j = 0; j <= nums3[i+100]; j++){
					r = (j*i)%m; 
					nums[i+100][r+100] = (nums[i+100][r+100] + combs(j,nums3[i+100]))%MODP;
				}
			}
			
			cout << (resps[m] = dp(-m+1,0)) << '\n';
		}
	}
}
