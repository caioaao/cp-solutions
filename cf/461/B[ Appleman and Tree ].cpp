#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int n;
vvi memo, ch;
vi cor;

ll mul_inv(ll a)
{
	ll b = mod, b0 = b, t, q;
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


void dp(int u){
  memo[u][cor[u]] = 1;
  memo[u][!cor[u]] = 0;
  
  for(size_t i = 0; i < ch[u].size(); i++){
    int v = ch[u][i];
    dp(v);
    memo[u][cor[u]] = (memo[u][cor[u]]*(memo[v][0]+memo[v][1]))%mod;
  }
  
  if(cor[u] == 0){
    for(size_t i = 0; i < ch[u].size(); i++){
      int v = ch[u][i];
      memo[u][1] = (memo[u][1] + ((memo[u][0]*mul_inv(memo[v][0]+memo[v][1]))%mod)*memo[v][1])%mod;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  ch.assign(n,vi());
  int v;
  for(int u = 1; u < n; u++){
    cin >> v;
    ch[v].push_back(u);
  }
  cor.assign(n,0);
  for(int i = 0; i < n; i++) cin >> cor[i];
  
  memo.assign(n,vi(2,-1));
  dp(0);
  cout << memo[0][1] << &#39;\n&#39;;
}
