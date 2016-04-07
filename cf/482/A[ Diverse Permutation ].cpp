#include <bits/stdc++.h>

#define MAXN 100100

using namespace std;
typedef long long L;
typedef double D;

bool u[MAXN];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  L n, k;
  while(cin >> n >> k){
    for(int i = 1; i <= n; i++) u[i] = 0;
    L i1 = 1, i2 = k+1;
    while(i1 < i2){
      u[i1] = 1; u[i2] = 1;
      cout << i1++ << &#39; &#39; << i2-- << &#39; &#39;;
    }
    for(int i = 1; i <= n; i++)if(!u[i])
      cout << i << &#39; &#39;;
    cout << &#39;\n&#39;;
  }
}
