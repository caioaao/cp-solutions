#include <bits/stdc++.h>

#define EPS 1e-8

using namespace std;

struct point{
  double x, y;
  point(): x(0), y(0){}
  point(double x, double y):
    x(x), y(y){}
};

struct line{
  double a, b, c;
  line(): a(0), b(0), c(0){}
  line(double a, double b, double c):
    a(a), b(b), c(c) {}
};
typedef point vec;

inline double dist(point a, point b){ return hypot(a.x-b.x,a.y-b.y); }

inline vec toVec(point a, point b){
  return vec(b.x-a.x,b.y-a.y);
}
inline vec scale(vec v, double s){
  return vec(v.x*s,v.y*s);
}
inline point translate(point p, vec v){return point(p.x+v.x,p.y+v.y); }

inline bool areParallel(line l1, line l2){ return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);}

inline bool areIntersect(line l1, line l2, point &p){
  if(areParallel(l1,l2)) return false;
  p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b -l1.a*l2.b);
  if(fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
  else                 p.y = -(l2.a*p.x + l2.c);
  return true;
}

void pointsToLine(point p1, point p2, line &l){
  if(fabs(p1.x - p2.x) < EPS){
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }else{
    l.a = -(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1;
    l.c = -(l.a*p1.x) - p1.y;
  }
}

inline double perimeter(double ab, double bc, double ca){ return ab+bc+ca; }

inline double area(double ab, double bc, double ca){
  double s = perimeter(ab,bc,ca)*.5;
  return (sqrt(s*(s-ab)*(s-bc)*(s-ca)));
}

bool circumCircle(point p1, point p2, point p3, point &ctr){
  if(fabs(area(dist(p1,p2),dist(p2,p3),dist(p3,p1))) < EPS) return false;
  
  double a,b,c,d,e,f,g;
  a = p2.x - p1.x;
  b = p2.y - p1.y;
  c = p3.x - p1.x;
  d = p3.y - p1.y;
  e = a*(p1.x + p2.x) + b*(p1.y + p2.y);
  f = c*(p1.x + p3.x) + d*(p1.y + p3.y);
  g = 2.0*(a*(p3.y-p2.y) - b*(p3.x-p2.x));
  if(fabs(g) < EPS) return false;
  ctr.x = (d*e - b*f)/g;
  ctr.y = (a*f - c*e)/g;
  return true;
}

vector<point> pts;
vector<bool> visited;
int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n){
    if(n == 0) break;
    pts.assign(n,point());
    for(int i = 0; i < n; i++){
      cin >> pts[i].x >> pts[i].y;
    }
    
    if(n <= 2){
      cout << "2\n";
      continue;
    }
    
    point c;
    double r;
    int ans = 2;
    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        visited.assign(n,0);
        
        for(int k = j+1; k < n; k++)if(!visited[k]){
          visited[k] = 1;
          if(!circumCircle(pts[i],pts[j],pts[k], c)) continue;
          r = dist(pts[i],c);
          //~ cout << i << ' ' << j << ' ' << k << ':' << c.x << ',' << c.y << endl;
          int cnt = 3;
          
          for(int x = k+1; x < n; x++){
            //~ cout << fabs(dist(pts[x],c) - r) << '\n';
            if(fabs(dist(pts[x],c) - r) < EPS){
              visited[x] = 1;
              cnt++;
            }
          }
          ans = max(ans,cnt);
        }
      }
    }
    cout << ans << '\n';
  }
}
