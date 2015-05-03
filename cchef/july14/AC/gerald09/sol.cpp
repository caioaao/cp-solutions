#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int t, n, m, k;
  char grid[15][15];
  cin >> t;
  while(t--){
    cin >> n >> m >> k;
    memset(grid, 'A', sizeof grid);
    if(k > n*m){
      k -= n*m;
      if(k > sqrt(n*m)) grid[n/2][m/2] = 'C';
      
    }
    for(int i = 0; i < n; i++, cout << '\n')
       for(int j = 0; j < m; j++) cout << grid[i][j];
  }
}
