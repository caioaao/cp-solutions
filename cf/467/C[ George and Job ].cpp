#include <bits/stdc++.h>

#define MAXN 5001
#define MAXK 5001
#define MAXM 5001
#define inf 1e17

using namespace std;
typedef long long ll;

ll memo[MAXN][MAXK];
bool mf[MAXN][MAXK];
int n, m, k;
ll s[MAXN];

ll dp(int id, int kl){
  if(id > n) return -inf;
  if(kl == 0) return 0;
  if(id == n) return -inf;
  if(mf[id][kl]) return memo[id][kl];
  mf[id][kl] = 1;
  return memo[id][kl] = max(dp(id+1,kl), dp(id+m, kl-1) + s[id+m-1] - (id > 0 ? s[id-1] : 0));
}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> n >> m >> k){
    ll x;
    cin >> s[0];
    for(int i = 1; i < n; i++){
      cin >> x;
      s[i] = s[i-1] + x;
    }
    memset(mf, 0, sizeof mf);
    cout << dp(0,k) << &#39;\n&#39;;
  }
}
