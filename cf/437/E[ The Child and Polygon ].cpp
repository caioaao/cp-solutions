#include <bits/stdc++.h>

#define mod 1000000007

#define MAXN 202

using namespace std;
typedef long long L;

struct point{
  L x, y;
  point(){}
  point(L x, L y):
    x(x), y(y) { }
};

inline point toVec(point a, point b){ return point(b.x-a.x,b.y-a.y); }
inline L cross(point a, point b){ return a.x * b.y - a.y * b.x; }

L memo[MAXN][MAXN];

point pts[MAXN];
L dp(int l, int r){
  if(r - l == 1) return 1;
  if(memo[l][r] == -1){
    memo[l][r] = 0;
    for(int i = l+1; i < r; i++){
      if(cross(toVec(pts[l],pts[r]),toVec(pts[i],pts[r])) > 0)
        memo[l][r] = ( memo[l][r] + dp(l,i) * dp(i,r) ) % mod;
    }
  }
  return memo[l][r];
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  memset(memo,-1,sizeof memo);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> pts[i].x >> pts[i].y;
  }
  L area = 0;
  for(int i = 0; i < n; i++){
    int j = (i+1)%n;
    area += cross(pts[i],pts[j]);
  }
  if(area < 0) reverse(pts,pts+n);
  
  memset(memo, -1, sizeof memo);
  cout << dp(0,n-1) << &#39;\n&#39;;
}
