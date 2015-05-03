#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    int n, m, x, ma, tot = 0, eq = 1;
    cin >> n >> m;
    cin >> ma;
    for(int i = 1; i < n; i++){
      cin >> x;
      if(x < ma)
        tot += ma-x;
      else if(x > ma){
        tot += (x-ma)*eq;
        ma = x;
      }
      eq++;
    }
    cout << ((tot <= m && (m-tot)%n == 0) ? "Yes\n" : "No\n");
  }
}
