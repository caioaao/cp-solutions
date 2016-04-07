#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  double sol;
  while(cin >> n >> m){
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    sol = 0;
    int a, b, c;
    for(int i = 0; i < m; i++){
      cin >> a >> b >> c;
      sol = max(sol, (w[a-1] + w[b-1])/(double)c);
    } 
    cout << fixed << setprecision(12) << sol << &#39;\n&#39;;
  }
}
