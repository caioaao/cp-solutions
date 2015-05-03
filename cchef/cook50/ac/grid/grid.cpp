#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

bool okc[MAXN][MAXN], rocks[MAXN][MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  int t, n;
  cin >> t;
  
  while(t--){
    cin >> n;
    char ro;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        okc[i][j] = 0;
        cin >> ro;
        rocks[i][j] = ro == '#';
      }
    }
    for(int k = 0; k < n; k++) for(int i = n-1; i >= 0; i--){
        if(rocks[i][k]) break;
        okc[i][k] = 1;
    }
    int ans = 0;
    for(int k = 0; k < n; k++) for(int j = n-1; j >= 0; j--){
        if(rocks[k][j]) break;
        ans += okc[k][j];
    }
    cout << ans << '\n';
  }
}
