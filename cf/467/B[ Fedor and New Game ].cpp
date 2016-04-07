#include <bits/stdc++.h>

#define MAXM 1001

using namespace std;

int vals[MAXM];

int main(){
  ios_base::sync_with_stdio(false);
  
  int n, m, k;
  while(cin >> n >> m >> k){
    int x;
    for(int i = 0; i < m; i++){
      cin >> vals[i];
    }
    cin >> x;
    int f = 0;
    for(int i = 0; i < m; i++){
      f += __builtin_popcount(vals[i]^x) <= k;
    }
    cout << f << &#39;\n&#39;;
  }
}
