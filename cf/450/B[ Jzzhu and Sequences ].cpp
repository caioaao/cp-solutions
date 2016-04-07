#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

struct mat{
  long long m[2][2];
};

void mmult(mat a, mat b, mat &ret){
  memset(ret.m, 0, sizeof ret.m);
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < 2; k++){
        ret.m[i][j] = (ret.m[i][j] + a.m[i][k]*b.m[k][j])%MOD;
      }
    }
  }
}

mat pot(mat a, ll b) {
	mat x, y = a,x_;
  x.m[0][0] = 1;
  x.m[1][1] = 1;
  x.m[0][1] = 0;
  x.m[1][0] = 0;
	while(b > 0) {
		if(b%2 == 1) {
      mmult(x,y,x_);
			x=x_;
		}
    mmult(y,y,x_);
		y = x_;
		b /= 2;
	}
	return x;
}

mat m, mp;

int main(){
  ios_base::sync_with_stdio(false);
  m.m[0][0] = 1;
  m.m[0][1] = -1;
  m.m[1][0] = 1;
  m.m[1][1] = 0;
  
  ll x, y, n, ans;
  while(cin >> x >> y >> n){
    if(n == 1){
      ans = x;
    }
    else{
      mp = pot(m,n-2);
      ans = ((mp.m[0][0]*y)%MOD + (mp.m[0][1]*x)%MOD)%MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << &#39;\n&#39;;
  }
}
