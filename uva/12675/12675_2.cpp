#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <functional>
#include <algorithm>
#include <cassert>
   
#define PI 1.157079632679
#define EPS 1e-7
   
using namespace std;
typedef long long ll;
   
struct point{
    ll x, y;
    point(){}
    point (ll _x, ll _y){x = _x; y = _y;}
    bool operator==(point other) const{ return x == other.x && y == other.y; }
    point operator+(point other) const{ return point(x+other.x, y+other.y); }
    point operator-(point other) const{ return point(x-other.x, y-other.y); }
};
   
point ax(1,0), ay(0,1);
   
point seeker;
   
typedef point vec;
   
inline vec toVec(point a, point b){ return vec(b.x - a.x, b.y - a.y);}
   
inline ll cross(vec a, vec b){ return a.x*b.y - b.x*a.y; }
   
inline bool ccw(point o, point a, point b){ return cross(toVec(o,a),toVec(o,b)) > 0; }
  
  
// using this before sorting by cross vector operation -> guarantees transitivity property needed for sorting(if a > b, b> c then c > a)
// returns quadrant of a point A wrt rotation center O
inline int quadrant(point o, point a){
    point a1 = a-o;
    if(a1.x > 0 && a1.y >= 0) return 0;
    if(a1.x <= 0 && a1.y > 0) return 1;
    if(a1.x < 0 && a1.y <= 0) return 2;
    if(a1.x >= 0 && a1.y < 0) return 3;
    return 0;
}
   
#define LINE_TYPE   0
#define KID_TYPE    1
#define LINE_BEGIN  0
#define LINE_END    1
   
struct evt{
    point p;
    int type, id;
    bool inicio;
       
    evt(){}
    evt(point _p, int _id, int _type, bool _inicio){ p = _p; id = _id; type = _type; inicio = _inicio;}
    bool operator>(evt lhs) const{
        int qR = quadrant(seeker, p),
            qL = quadrant(seeker, lhs.p);
   
        if(qR > qL) return true;
        if(qR < qL) return false;
           
        if(ccw(seeker, lhs.p, p)) return true;
        if(ccw(seeker, p, lhs.p)) return false;
           
        if(type == LINE_TYPE && lhs.type == KID_TYPE){
            if(inicio == LINE_BEGIN) return false;
            if(inicio == LINE_END)   return true;
        }
           
        if(type == KID_TYPE && lhs.type == LINE_TYPE){
            if(lhs.inicio == LINE_BEGIN) return true;
            if(lhs.inicio == LINE_END)   return false;
        }
           
        if(type == LINE_TYPE && lhs.type == LINE_TYPE){
            if(inicio == LINE_BEGIN) return false;
            else                     return true;
               
        }
           
        return true;
    }
    bool operator<(evt other) const{ return !(evt(p,id,type,inicio)>other);}
};
   
int s, k, w, h;
   
#define MAX_K 10010
#define MAX_W 10010
   
priority_queue<evt, vector<evt>, greater<evt> > pq;
vector<point> hiding(MAX_K);
vector<pair<point, point> > walls(MAX_W);
   
inline bool cmpActive(int a, int b){
  if(a == b){
    return false;
  }
   
  if(ccw(seeker, walls[a].first, walls[b].first) && !ccw(seeker, walls[a].second, walls[b].first)){
    return ccw(walls[a].first, walls[a].second, walls[b].first) !=  ccw(walls[a].first, walls[a].second, seeker);
  }
  else if(ccw(seeker, walls[a].first, walls[b].second) && !ccw(seeker, walls[a].second, walls[b].second)){
    return ccw(walls[a].first, walls[a].second, walls[b].second) !=  ccw(walls[a].first, walls[a].second, seeker);
  }
  else{// completamente contido no intervalo b
    return ccw(walls[b].first, walls[b].second, walls[a].first) == ccw(walls[b].first, walls[b].second, seeker);
  }
}
   
set<int, bool(*)(int a, int b)> activeLines(cmpActive);
int main(){
      while(scanf("%d%d%d",&s,&k,&w) != EOF){
        for (int i = 0; i < k; i++)
            scanf("%lld%lld",&hiding[i].x, &hiding[i].y);
           
        for(int i = 0; i < w; i++)
            scanf("%lld%lld%lld%lld",&walls[i].first.x, &walls[i].first.y, &walls[i].second.x, &walls[i].second.y);
              
        // for each seeker kid
        for(int i = 0; i < s; i++){
            seeker = hiding[i]; // set up global variable
            ll ans = 0;
            activeLines.clear(); // clear active (opened) intervals of line segments
            for(int j = 0; j < w; j++){
                // sort begin-end of an interval by rotation direction( CW or CCW) around seeker
                if(!ccw(seeker, walls[j].first, walls[j].second)){
                    swap(walls[j].first, walls[j].second);
                }
                  
                // puts segment's ends in a priority queue, sorted by angle wrt the X axis that
                // passes through seeker
                pq.push(evt(walls[j].first,  j, LINE_TYPE, LINE_BEGIN));
                pq.push(evt(walls[j].second, j, LINE_TYPE, LINE_END));
                  
                // if the segment crosses the X axis, put another segment begining in angle=0 (so the angle sort works)
                if(quadrant(seeker, walls[j].first) >  quadrant(seeker, walls[j].second)){
                    pq.push(evt(seeker + ax, j, LINE_TYPE, LINE_BEGIN));
                }
            }
              
            // for each kid that's hiding, put them on priority queue as well
            for(int j = 0; j < k; j++){
                if(j == i) continue;
                pq.push(evt(hiding[j], j, KID_TYPE,false));
            }
         
            // sweep circle
            while(!pq.empty()){
                evt curr = pq.top(); pq.pop(); // current event
                   
                if(curr.type == LINE_TYPE){
                    if(curr.inicio == LINE_END){
                        activeLines.erase(curr.id);
            }
                    else{
                        // add line to active segments
                        activeLines.insert(curr.id);
            }
        }
                else if(curr.type == KID_TYPE){
                    // if event is of type KID, queries set of active segments for the closer segment to the seeker
                    // if there is any segment between kid and seeker, than the closest segment will be between them as well.
                    // this is also true if there isn't a segment, so it's enough to check just the first segment
                    if(activeLines.empty() || ccw(walls[*activeLines.begin()].first, walls[*activeLines.begin()].second, curr.p) == ccw(walls[*activeLines.begin()].first, walls[*activeLines.begin()].second, seeker)){
                        ans++;
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
}
