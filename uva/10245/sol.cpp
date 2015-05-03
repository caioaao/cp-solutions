#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 2000000000

struct point{
  double x, y;
  point(): x(0),y(0){ }
  point(double _x, double _y): x(_x), y(_y){ }
};

typedef set<point>::const_iterator sit;

// Ordena por X crescente e desempate por Y crescente (p/ eventos)
bool x_cmp(point lhs, point rhs){
  if(lhs.x < rhs.x) return true;
  else if(lhs.x > rhs.x) return false;
  return lhs.y < rhs.y;
}

// Ordena por Y crescente e desempata por X crescente
bool y_cmp(point lhs, point rhs){
  if(lhs.y < rhs.y) return true;
  else if(lhs.y > rhs.y) return false;
  else return lhs.x < rhs.x;
}

// distancia
inline double dist(point a, point b){ return hypot(a.x-b.x, a.y-b.y); }

vector<point> pts;
set<point, bool(*)(point a, point b)> ativos(y_cmp);
stack<point> tbd;
int main(){
  ios_base::sync_with_stdio(false);

  int n;
  while(cin >> n && n != 0){
    pts.assign(n, point());
    ativos.clear();
    for(int i = 0; i < n; i++){
      cin >> pts[i].x >> pts[i].y;
    }
    
    double ans = INF;
    point curr;
    sit lo, hi;
    sort(pts.begin(), pts.end(), x_cmp);
    for(int i = 0; i < n; i++){
      curr = pts[i];
      
      lo = ativos.lower_bound(point(curr.x - ans, curr.y - ans));
      hi = ativos.lower_bound(point(curr.x      , curr.y + ans));
      
      for(sit it = lo; it != ativos.end(); ++it){
        //~ cout << '(' << curr.x << ',' << curr.y << ") -> (" << it->x << ',' << it->y << ") = " << sqrt(dist2(curr,*it)) << endl;
        if(curr.x - ans >= it->x){
          tbd.push(*it);
        }else{
          ans = min(ans,dist(curr,*it));
          if(it == hi) break;
        }
      }
      while(!tbd.empty()){
        ativos.erase(tbd.top());
        tbd.pop();
      }
      
      ativos.insert(curr);
    }
    if(ans >= 10000){
      cout << "INFINITY\n";
    }
    else{
      cout << fixed << setprecision(4) << ans << '\n';
    }
  }
}
