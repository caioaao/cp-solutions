#include <bits/stdc++.h>

#define INF 1000
#define mod 1000000007

#define MAXH 2000
#define MAXN 2000001

using namespace std;

#define S(x) ((x)*((x)+1))/2

int memo[2][MAXN], r, g;

int calcH(){
  bool f = 0;
  int rU, gU, h;
  memo[f][1] = (r >= 1);
  memo[f][0] = (g >= 1);
  bool ok = 1;
  while(ok){
    f ^= 1; h++;
    
    ok = 0;
    
    for(rU = 0; rU <= min(r,S(h)); rU++){
      gU = S(h) - rU;
      memo[f][rU] = 0;
      if(rU <= r && gU <= g){
        if(rU >= h) memo[f][rU] = memo[!f][rU - h];
        if(gU >= h) memo[f][rU] |= memo[!f][rU];
      }
      if(memo[f][rU]) ok = 1;
    }
  }
  
  return h-1;
}

int calc(int H){
  bool f = 0;
  int rU, gU;
  memo[f][1] = (r >= 1);
  memo[f][0] = (g >= 1);
  f ^= 1;
  for(int h = 2; h <= H; h++, f ^= 1){
    for(rU = 0; rU <= min(r,S(h)); rU++){
      gU = S(h) - rU;
      memo[f][rU] = 0;
      if(rU <= r && gU <= g){
        if(rU >= h) memo[f][rU] += memo[!f][rU - h];
        if(gU >= h) memo[f][rU] += memo[!f][rU];
      }
      if(memo[f][rU] >= mod) memo[f][rU] %= mod;
    }
  }
  f ^= 1;
  int ans = 0;
  for(int i = 0; i <= min(r,S(H)); i++){
    ans += memo[f][i];
    if(ans >= mod) ans %= mod;
  }
  return ans;
}

int main(){
  while(cin >> r >> g){
    int h =  calcH();
    //cout << h << &#39;\n&#39;;
    cout << calc(h) << &#39;\n&#39;;
  }
}
