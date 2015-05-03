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
 
ll nums[2*MAX_M][2*MAX_M], nums2[MAX_N], nums3[2*MAX_M];
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

ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
 
void calcFacs(){
	facs[0] = 1;
	facsInv[0] = 1;
	for(ll i = 1; i <= 100000; i++){
		facs[i] = ((facs[i-1])%MODP*(i%MODP))%MODP;
		facsInv[i] = (facsInv[i-1]*mul_inv(i,MODP))%MODP;
	}
	//~ cout << facs[100000] << endl;
	//~ cout << facsInv[77012] << ' ' << facsInv[100000-77012] << endl;
}

ll combs(ll k, ll els){
	if(k == 0) return 1;
	return (facs[els]*(facsInv[k]%MODP*facsInv[els-k]%MODP)%MODP)%MODP;
}
 
ll dp(ll num, ll resto){
	if(num == m && resto%m == 0) return 1;
	if(num == m) return 0;
	if(num == 0) return memo[num+100][resto+100] = dp(num+1,resto);
	
	if(memo[num+100][resto+100] != -1) return memo[num+100][resto+100];
	
	memo[num+100][resto+100] = (nums[num+100][100]*dp(num+1,(resto)%m))%MODP;
	for(ll i = 1; i < m; i++){
		memo[num+100][resto+100] = (memo[num+100][resto+100] + (nums[num+100][i+100]*dp(num+1,(resto+i)%m))%MODP)%MODP;
		memo[num+100][resto+100] = (memo[num+100][resto+100] + (nums[num+100][100-i]*dp(num+1,(resto-i)%m))%MODP)%MODP;
	}
 
	return memo[num+100][resto+100] = memo[num+100][resto+100]%MODP;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	
	int T;
	
	cin >> T;
	//~ T = 0;
	ll r;
	calcFacs();
	//~ return 0;
	while(T--){
		n3 = 0;
		cin >> n2 >> q;
		for(int i = 0; i < n2; i++)
			cin >> nums2[i];
		
		while(q--){
			cin >> m;
			
			memset(nums3, 0, sizeof nums3);
			memset(memo,-1,sizeof memo);
			memset(nums, 0, sizeof nums);

			// O(N)
			for(ll i = 0; i < n2; i++){
				nums3[(nums2[i]%m) + 100]++;
			}
			
			
			// O(N)
			for(ll i = -m+1; i < m; i++){
				for(ll j = 0; j <= nums3[i+100]; j++){
					r = (j*i)%m;
					
					nums[i+100][r+100] = (nums[i+100][r+100] + combs(j,nums3[i+100]))%MODP;
			
				}
			}
			
			
			//////////////////////////////////////////////
			//~ cout << m << ':' << endl;
			//~ for(int i = -m+1; i < m; i++){
				//~ cout << i << ':';
				//~ for(int j = -m+1; j < m; j++){
					//~ cout << ' ' << nums[i+100][j+100];
				//~ }
				//~ cout << endl;
			//~ }
				//~ cout << endl;
			//~ cout << endl;
			
			//////////////////////////////////////////////
			
			// O(m^2)
			cout << (pot(2,nums3[100],MODP)*dp(-m+1,0))%MODP << '\n';
		}
	}
}
