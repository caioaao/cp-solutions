#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;
typedef double dd;

dd N,M;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  while(cin >> N >> M){
    dd ans;
    if(M > 1)
      ans = 1./N + (((N-1)/N)*(M-1)/(N*M-1));
    else
      ans = 1./N;
    
    
    cout << ans << &#39;\n&#39;;
  }
}
