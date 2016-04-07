#include <bits/stdc++.h>

#define MAXN 100100

using namespace std;
typedef long long L;
typedef double D;

bool u[MAXN];

L gcd(L a, L b){ return (b == 0 ? a : gcd(b,a%b)); }

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  L l,r;
  while(cin >> l >> r){
    bool ok = false;
    L i, j, k;
    for(i = l; i <= r; i++)
      for(j = i+1; j <= r; j++)
        for(k = j+1; k <= r; k++)
          if(gcd(i,j) == 1 && gcd(j,k) == 1 && gcd(i,k) != 1){
            ok = true;
            goto fim;
          }
          
    fim:
    if(ok) {
      cout << i << &#39; &#39; << j << &#39; &#39; << k << &#39;\n&#39;;
    }
    else{
      cout << "-1\n";
    }
  }
}
