#include <bits/stdc++.h>

using namespace std;

struct point{
  int x, y;
  point() : x(0),y(0){ }
  point(int _x, int _y) : x(_x), y(_y){ }
};

inline int dot(point a, point b){ return a.x*b.x + a.y*b.y; }
inline point toVec(point a, point b){ return point(b.x-a.x,b.y-a.y); }

int main(){
  ios_base::sync_with_stdio(false);
  int n, ans = 0;
  cin >> n;
  point a,b,c, ab, bc, ca;
  while(n--){
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ab = toVec(a,b);
    bc = toVec(b,c);
    ca = toVec(c,a);
    if(!dot(ab,bc) || !dot(bc,ca) || !dot(ab,ca)) ans++;
  }
  cout << ans << '\n';
}
