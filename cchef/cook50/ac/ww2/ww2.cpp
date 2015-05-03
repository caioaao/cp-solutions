#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef vector<vii> vvii;
typedef vvii matrix;

matrix I;

matrix mmul(matrix &a, matrix &b){
  //assert(a[0].size() == b.size());
  int m = a.size(), n = b[0].size(), mi = a[0].size();
  
  matrix ret(m, vii(n, 0));
  
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < mi; k++){
        ret[i][j] = ret[i][j] + (a[i][k] * b[k][j]);
        if(ret[i][j] >= mod) ret[i][j]  %= mod;
      }
  return ret;
}

matrix pot(matrix a, ll b) {
	matrix x = I, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=mmul(x,y);
		}
		y = mmul(y,y);
		b /= 2;
	}
	return x;
}


#define ok(x) (x) >= 0 && (x) < m
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  matrix mat, res;
  ll n, m;
  
  int t;
  
  cin >> t;
  
  while(t--){
    cin >> n >> m;
    
    I.assign(m*2,vii(m*2,0));
    
    mat.assign(m*2,vii(m*2,0));
    
    for(int i = 0; i < m*2; i++) I[i][i] = 1;
    
    for(int i = 0; i < m; i++){
      mat[m+i][i] = 1;
      if(ok(i-1)) mat[i][m+i-1] = mat[m+i][i-1] = 1;
      if(ok(i+1)) mat[i][m+i+1] = mat[m+i][i+1] = 1;
    }
    
    //for(int i = 0; i < 2*m; i++){
      //cout << i <<": ";
      //for(int j = 0; j < 2*m; j++)
        //cout << mat[i][j] << ' ';
      //cout << endl;
    //}
    
    res = pot(mat, n-1);
    
    ll ans = 0;
    
    if(n & 1)
      for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++){
          ans += res[i][j];
          if(ans >= mod) ans %= mod;
        }
    else
      for(int i = 0; i < m; i++)
        for(int j = m; j < 2*m; j++){
          ans += res[i][j];
          if(ans >= mod) ans %= mod;
        }

    cout << ans << '\n'; 
  }
}
