#include <bits/stdc++.h>

#define INF 1e12

using namespace std;

struct point{
  int x,y;
  point(){;}
};

inline double dist(point a, point b){
  return hypot(a.x-b.x,a.y-b.y);
}

int n;
vector<point> pts;
double memo[(1<<17)];
double dp(int bm){
  if(memo[bm] >= 0)
    return memo[bm];
  if(bm == (1<<(2*n)) - 1) return 0;
  memo[bm] = INF;
  for(int i = 0; i < 2*n; i++){
    for(int j = i+1; j < 2*n; j++){
      if((bm & (1 << i)) != 0 || (bm & (1 << j)) != 0) continue;
      memo[bm] = min(memo[bm], dp(bm | ((1 << i) | (1 << j))) + dist(pts[i], pts[j]));
    }
  }
  return memo[bm];
}

int main(){
  ios_base::sync_with_stdio(false);
  string dummy;
  int caso = 1;
  while(cin >> n, n != 0){
    pts.assign(2*n,point());
    for (int i = 0; i < 2*n; i++){
      cin >> dummy >> pts[i].x >> pts[i].y;
    }
    memset(memo,-1,sizeof memo);
    cout << "Case " << caso++ << ": " << fixed << setprecision(2) << dp(0) << '\n';
  }
}
