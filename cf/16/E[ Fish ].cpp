#include <bits/stdc++.h>

using namespace std;

double m[20][20];
double memo[1<<18];
bool is_m[1<<18];
int n;

double dp(int bm){
  if(bm + 1 == (1 << n)) return 1;
  if(is_m[bm]) return memo[bm];
  is_m[bm] = 1.0;
  memo[bm] = 0.0;
  int ct = __builtin_popcount(bm)+1;
  for(int i = 0; i < n; i++) if(bm &(1 << i)){
    for(int j = 0; j < n; j++)if(!(bm & (1 << j))){
      memo[bm] += m[i][j]*dp(bm | (1 << j))*2/(ct*(ct-1));
    }
  }
  return memo[bm];
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> m[i][j];
  
  memset(is_m,0,sizeof is_m);
  for(int i = 0; i < n; i++) cout << fixed << setprecision(10) << dp(1<<i) << &#39; &#39;;
}
