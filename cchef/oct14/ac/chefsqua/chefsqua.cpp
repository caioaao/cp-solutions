#include <bits/stdc++.h>
#define eps 1e-10
using namespace std;
typedef long long ll;
typedef double base;

struct point{
  base x,y;
  
  point(){}
  point(base x, base y):
    x(x), y(y){ }
  bool operator< (const point & rhs) const{
    if(fabs(x - rhs.x) < eps && fabs(y - rhs.y) < eps) return false;
    if(x < rhs.x) return true;
    if(x > rhs.x) return false;
    return y < rhs.y;
  }
};

vector<point> pts;
set<point> exists;

const double pi = acos(-1.0);
const double sin90 = sin(pi/2), cos90 = cos(pi/2), nsin90 = sin(-pi/2), ncos90 = cos(-pi/2);


inline bool is_int(point & p){
  return fabs(round(p.x) - p.x) < eps && fabs(round(p.y) - p.y) < eps;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  while(cin >> n){
    if(n == 0){
      cout << "4\n";
      continue;
    }
    pts.assign(n,point());
    exists.clear();
    for(int i = 0; i < n; i++){
      cin >> pts[i].x >> pts[i].y;
      exists.insert(pts[i]);
    }
    
    if(n < 3){
      if(n == 2) cout << "2\n";
      if(n == 1) cout << "3\n";
      continue;
    }
    point a,b,p,q,mi;
    int best = 2, aux;
    for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
      a = pts[i], b = pts[j];
      mi.x = (a.x+b.x)/2; mi.y = (a.y+b.y)/2;
      
      // case 1: pair is the diagonal
      
      p.x = (a.x - mi.x)*cos90 - (a.y - mi.y) * sin90 + mi.x;
      p.y = (a.x - mi.x)*sin90 + (a.y - mi.y) * cos90 + mi.y;
      
      q.x = (b.x - mi.x)*cos90 - (b.y - mi.y) * sin90 + mi.x;
      q.y = (b.x - mi.x)*sin90 + (b.y - mi.y) * cos90 + mi.y;
      
      
      aux = !(is_int(p) && exists.count(p)) + !(is_int(q) && exists.count(q));
      best = min(best,aux);
      if(best == 0) goto fim;
      
      
      // case 2: "left" square
      p.x = (b.x - a.x)*cos90 - (b.y - a.y) * sin90 + a.x;
      p.y = (b.x - a.x)*sin90 + (b.y - a.y) * cos90 + a.y;
      
      q.x = (a.x - b.x)*ncos90 - (a.y - b.y) * nsin90 + b.x;
      q.y = (a.x - b.x)*nsin90 + (a.y - b.y) * ncos90 + b.y;
      
      aux = !(is_int(p) && exists.count(p)) + !(is_int(q) && exists.count(q));
      best = min(best,aux);
      if(best == 0) goto fim;
      
       //case 3: "right" square
      //p.x = (b.x - a.x)*ncos90 - (b.y - a.y) * nsin90 + a.x;
      //p.y = (b.x - a.x)*nsin90 + (b.y - a.y) * ncos90 + a.y;
      //
      //q.x = (a.x - b.x)*cos90 - (a.y - b.y) * sin90 + b.x;
      //q.y = (a.x - b.x)*sin90 + (a.y - b.y) * cos90 + b.y;
      //aux = !(is_int(p) && exists.count(p)) + !(is_int(q) && exists.count(q));
      //best = min(best,aux);
      //if(best == 0) goto fim;
    }
    fim:
    cout << best << '\n';
  }
}
