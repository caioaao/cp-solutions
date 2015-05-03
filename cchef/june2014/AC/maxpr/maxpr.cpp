#include <bits/stdc++.h>

#define MOD 1000000007ll
#define MAX_N 200002
#define MAX_A 101
#define MAX_R 201

using namespace std;
typedef long long ll;

int n, memo[MAX_N][MAX_A], next_ind[MAX_N][MAX_A], nums[MAX_N], pots[MAX_N];

void preproc(){ pots[0] = 1; for(int i = 1; i < MAX_N; i++) pots[i] = (2*pots[i-1])%MOD; }

int dp(){
	int nxt, last, r;
	for(int i = 0; i <= 100; i++) memo[n][i] = 0;
	memo[n][0] = 1;
	for(int id = n-1; id >= 0; id--){
		memo[id][0] = 1 + memo[id+1][0]; // pegando soh ele ou ignorando ele
		for(int i = 1; i <= 100; i++){
			last = i;
			memo[id][last] = memo[next_ind[id+1][nums[id]]][last]; // ignora id
			memo[id][last]++;// acabando em id
			
			r = nums[id] - last;
			
			nxt = nums[id]+r;
			if(nxt >=1 && nxt <=100){
				memo[id][last] = memo[id][last] + memo[next_ind[id+1][nxt]][nums[id]]; // pegando prox
        if(memo[id][last] >= MOD || memo[id][last] <= -MOD) memo[id][last] %= MOD;
      }
				
			///////////////////////
			nxt = i;
			memo[id][0] = memo[id][0] + memo[next_ind[id+1][nxt]][nums[id]];
      if(memo[id][0] >= MOD || memo[id][0] <= -MOD) memo[id][0] %= MOD;
		}
	}
	return memo[0][0];
}

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  
  preproc();
  
  while(t--){
    cin >> n;
    
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }
    
    for (int i = 1; i <= 100; i++){
      next_ind[n][i] = n;
    }

    for(int i = n-1; i >= 0; i--){
      for(int j = 1; j <= 100; j++)
        next_ind[i][j] = next_ind[i+1][j];
      next_ind[i][nums[i]] = i;
    }
    
    ll ans = pots[n];
    
    
    ans = ans - dp();
    if(ans >= MOD || ans <= -MOD) ans %= MOD;
    
    if(ans < 0) ans = MOD + ans;
    cout << ans << '\n';
  }
}
