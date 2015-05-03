#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
 
#define MAX_N 100510
#define MAX_M 110
#define MODP 1000000009
 
using namespace std;
typedef long long ll;
 
ll memo[MAX_N][2*MAX_M], n, n2, n3, q, m;
 
ll nums4[2*MAX_M][2*MAX_M], nums2[MAX_N], nums3[2*MAX_M], nums[MAX_N], numsAmt[MAX_N];
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
 

ll solve(){
	ll resps[2][MAX_M*2];
	memset(resps,0,sizeof resps);
	resps[0][m] = 1;
	ll nV;
	int curr = 1;
	// 0-1 knapsack (bottom up solution)
	for(ll i = 0; i < n; i++){
		for(ll j = -m+1; j < m; j++){
			nV = (j+nums[i])%m;
			resps[curr][j+m] = (resps[curr][j+m] + resps[!curr][j+m] )%MODP; // 0
			resps[curr][nV+m]  = (resps[curr][nV+m] + (resps[!curr][j+m]*numsAmt[i])%MODP )%MODP; // 1
		}
		curr = !curr;
		memset(resps[curr],0,sizeof resps[curr]);
	}
	//~ cout << "Zeros: " << zeros << ':' << pot(2,zeros,MODP) << endl;
	return resps[!curr][m];
	//~ return resps[!curr][m];
}

 
int main(){
	ios_base::sync_with_stdio(false);
	
	calcFacs();
	
	int T;
	
	cin >> T;
	
	
	ll r;
	
	while(T--){
		n3 = 0;
		cin >> n2 >> q;
		
		for(int i = 0; i < n2; i++)
			cin >> nums2[i];
		
		while(q--){
			cin >> m;
			
			memset(nums3, 0, sizeof nums3);
			memset(memo,-1,sizeof memo);
			memset(nums4, 0, sizeof nums4);

			// O(N)j
			for(ll i = 0; i < n2; i++){
				nums3[(nums2[i]%m) + 100]++;
			}
			
			
			//~ nums3[100]++;
			
			// O(N)
			for(ll i = -m+1; i < m; i++){
				for(ll j = 1; j <= nums3[i+100]; j++){
					r = (j*i)%m;
					//~ if(nums[i+100][r+100] == 0) deb++;
					
					nums4[i+100][r+100] = (nums4[i+100][r+100] + combs(j,nums3[i+100]))%MODP;
			
					//~ if(combs(j,nums3[i+100]) < 0) cout << "Combinacao de " << j << " em " << nums3[i+100] << endl;
				}
			}
			
			// O(m^2)
			n = 0;
			for(ll i = -m+1; i < m; i++){
				for(ll j = -m+1; j < m; j++){
					if(nums4[i+100][j+100] > 0){
						nums[n] = j;
						numsAmt[n] = nums4[i+100][j+100];
						n++;
					}
				}
			}
			
			//~ cout << "Debug:";
			//~ for(int i = 0; i < n; i++) cout << ' ' << nums[i] << ';' << numsAmt[i];
			//~ cout << endl;
			
			cout << (solve())%MODP << '\n';
		}
	}
}
