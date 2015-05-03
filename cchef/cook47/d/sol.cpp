#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct point{
  int x,y;
  point(){;}
  point(ll _x, ll _y){
    x = _x;
    y = _y;
  }
  bool operator<(const point rhs) const{
    if(x < rhs.x) return true;
    if(x > rhs.x) return false;
    return y < rhs.y;
  }
};

inline ll area2(point a, point b, point c){
  ll x1 = b.x - a.x,
     y1 = b.y - a.y,
     x2 = c.x - a.x,
     y2 = c.y - a.y;
  ll ret = x1*y2 - x2*y1;
  
  return max(ret,-ret);
}

vector<point> pts;

int b,c;
ll s;

inline ll area2(point k){ return area2(pts[b],pts[c],k); }

int ts(int left, int right){
  ll leftThird, rightThird;
  while(right - left >= 3){
    leftThird = left + (right - left + 1)/3;
    rightThird = right - (right - left + 1)/3;
    
    if(area2(pts[leftThird]) < area2(pts[rightThird]))
      left = leftThird;
    else
      right = rightThird;
  }
  
  int pos = left;
  for(int i = left; i <= right; i++)
    if(area2(pts[i]) > area2(pts[pos])) pos = i;
  return pos;
}

int bsmai(int lo, int hi){
  int mi, ret = hi+1;
  while(lo <= hi){
    mi = (lo+hi)/2;
    if(area2(pts[mi]) >= s){
      hi = mi-1;
      ret = min(ret,mi);
    }
    else lo = mi+1;
  }
  
  return ret;
}

int bsmen(int lo, int hi){
  int mi, ret = lo-1;
  while(lo <= hi){
    mi = (lo+hi)/2;
    if(area2(pts[mi]) >= s){
      lo = mi + 1;
      ret = max(ret,mi);
    }
    else hi = mi - 1;
  }
  return ret;
}


int query(int beg, int end){
  int mid = ts(beg,end);
  
  if(area2(pts[mid]) < s) return 0;
  
  int lb = bsmai(beg,mid-1), hb = bsmen(mid+1,end);
  
  return hb - lb + 1;
}

int main(){
  int n, q;
  scanf("%d %d", &n, &q);
  
  pts.assign(n,point());
  
  for(int i = 0; i < n; i++){
    scanf("%d %d", &pts[i].x, &pts[i].y);
  }
  
  while(q--){
    scanf("%d %d %lld\n", &b, &c, &s);
    
    s*=2;
    b--; c--;
    if(b > c) swap(b,c);
    
    printf("%d\n", query(b,c) + query (0,b) + query(c,pts.size()-1));
  }
}
