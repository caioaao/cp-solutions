#include <bits/stdc++.h>

#define MAXN 101000

using namespace std;
typedef long long L;

L fwd[MAXN], rwd[MAXN], v[MAXN];

L gcd(L a, L b){ return (b == 0 ? a : gcd(b, a%b)); }

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T, N, Q;
  L l,r, a, b;
  cin >> T;
  while(T--){
    cin >> N >> Q;
    
    for(int i = 0; i < N; i++){
      cin >> v[i];
    }
    fwd[0] = v[0];
    rwd[N-1] = v[N-1];
    for(int i = 1, ri = N-2; i < N; i++, ri--){
      fwd[i] = gcd(fwd[i-1], v[i]);
      rwd[ri] = gcd(rwd[ri+1], v[ri]);
    }

    
    while(Q--){
      cin >> l >> r;
      l-=2;
      
      

      a = (l < 0 ? 0 : fwd[l]);
      b = (r >= N ? 0 : rwd[r]);

      

      cout << gcd(a,b) << '\n';
    }
  }
}
