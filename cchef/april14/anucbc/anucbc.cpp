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
 
ll nums[2*MAX_M], nums2[MAX_N];
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
	//~ cout << facs[3] << endl;
	//~ cout << facsInv[2] << endl;
	//~ cout << facsInv[1] << endl;
}
 
ll combs(ll k, ll els){
	if(k == 0) return 1;
	return (facs[els]*(facsInv[k]*facsInv[els-k])%MODP)%MODP;
}
 
ll dp(ll num, ll resto){
	if(num == n && resto%m == 0) return 1;
	if(num == n) return 0;
	if(num == 0) return dp(1,resto);
	//~ cout << numId << endl;
	
	if(memo[num+100][resto+100] != -1) return memo[num+100][resto+100];
	
	memo[num+100][resto+100] = 0;
	ll s = 0;
	for(ll i = 0; i <= nums[num+100]; i++){
		ll res = (s+resto)%m;
		//~ cout << "num: " << num << 'x' << i << " de " << numsCount[num] << ':' << combs(i,numsCount[num]) << endl;
		memo[num+100][resto+100] = (memo[num+100][resto+100] + (combs(i,nums[num+100])*dp(num+1,res))%MODP)%MODP;
		s=(s+num%m)%m;
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
		//~ for(int i = 0; i < n; i++) cout << nums[i] << ' ' << numsCount[nums[i]] << endl;
		while(q--){
			cin >> m;
			memset(nums, 0, sizeof nums);
 
			memset(memo,-1,sizeof memo);
			n = m;
			
			for(ll i = 0; i < n2; i++){
				nums[(nums2[i]%m) + 100]++;
			}
			cout << (((ll)pow(2,nums[100]))*dp(-m+1,0)) << '\n';
		}
	}
}
