#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

const double PI = acos(-1.0);

struct point{
  double x, y;
  point(){x = y = 0;}
  point(double _x, double _y){
    x = _x;
    y = _y;
  }
  
  bool operator==(const point rhs) const{
    return fabs(x - rhs.x) < EPS  && fabs(y - rhs.y) < EPS;
  }
  
  bool operator<(const point rhs) const{
    if(x < rhs.x) return true;
    if(x == rhs.x) return y < rhs.y;
    return false;
  }
};
typedef point vec;

inline vec toVec(point a, point b){ return vec(b.x-a.x,b.y-a.y);}

inline double cross(point a, point b){ return a.x*b.y - a.y*b.x;}

inline bool ccw(point o, point a, point b){ return cross(toVec(o,a),toVec(o,b)) > 0; }

inline double dot(vec a, vec b){return a.x*b.x + a.y*b.y;}

inline double norm_sq(vec v){ return v.x*v.x + v.y*v.y;}

vector<point> ch, pA, pB;
point fountain;

double area(const vector<point> &P){
  double result = 0.0, x1, x2, y1, y2;
  for(int i = 0; i < (int)P.size()-1;i++){
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1*y2 - x2*y1);
  }
  return fabs(result)/2.0;
}

point lineIntersectSeg(point p, point q, point A, point B){
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x*B.y;
  double u = fabs(a * p.x + b*p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  
  return point((p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u)/(u+v));
}

void cutPolygon(point a, point b, vector<point> &Q){
  vector<point> P;
  for(int i = 0; i < (int)Q.size(); i++){
    double left1 = cross(toVec(a,b),toVec(a,Q[i])), left2 = 0;
    if(i != (int)Q.size() - 1) left2 = cross(toVec(a,b), toVec(a,Q[i+1]));
    if(left1 > -EPS) P.push_back(Q[i]);
    if(left1 * left2 <  -EPS)
      P.push_back(lineIntersectSeg(Q[i],Q[i+1],a,b));
  }
  if(!P.empty() && !(P.back() == P.front()))P.push_back(P.front());
  Q = P;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int n, caso = 1;
  double w, h;
  point pa, pb;
  while(cin >> n >> w >> h >> fountain.x >> fountain.y){
    cout << "Case #" << caso++ << ": ";
    ch.assign(5,point());
    ch[0] = point(0.0,0.0);
    ch[1] = point(w,0.0);
    ch[2] = point(w,h);
    ch[3] = point(0.0,h);
    ch[0] = point(0.0,0.0);
    for (int i = 0; i < n; i++)
    {
      cin >> pa.x >> pa.y;
      cin >> pb.x >> pb.y;
      if(ccw(pa,pb,fountain))
        cutPolygon(pa,pb,ch);
      else
        cutPolygon(pb,pa,ch);
    }
    
    cout << fixed << setprecision(3) << area(ch) << '\n';
  }
}
