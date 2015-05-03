#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <functional>
#include <algorithm>
#include <cassert>
   
using namespace std;
typedef long long ll;
   
struct point{
    ll x, y;
    point(){}
    point (ll _x, ll _y){x = _x; y = _y;}
    bool operator==(const point &other) const{ return x == other.x && y == other.y; }
    point operator+(const point & other) const{ return point(x+other.x, y+other.y); }
    point operator-(const point & other) const{ return point(x-other.x, y-other.y); }
};
   
point ax(1,0), ay(0,1);
   
point seeker;
   
typedef point vec;

inline bool ccw(const vec &a, const vec &b){ return a.x*b.y - b.x*a.y > 0; }
   
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
    bool operator>(const evt &lhs) const{
        if(p.y < seeker.y && lhs.p.y >= seeker.y) return true;
        if(p.y >= seeker.y && lhs.p.y < seeker.y) return false;
           
        if(ccw(lhs.p-seeker, p-seeker)) return true;
        if(ccw(p-seeker, lhs.p-seeker)) return false;
           
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
    bool operator<(const evt &lhs) const{
      
        if(p.y < seeker.y && lhs.p.y >= seeker.y) return false;
        if(p.y >= seeker.y && lhs.p.y < seeker.y) return true;
           
        if(ccw(lhs.p-seeker, p-seeker)) return false;
        if(ccw(p-seeker, lhs.p-seeker)) return true;
           
        if(type == LINE_TYPE && lhs.type == KID_TYPE){
            if(inicio == LINE_BEGIN) return true;
            if(inicio == LINE_END)   return false;
        }
           
        if(type == KID_TYPE && lhs.type == LINE_TYPE){
            if(lhs.inicio == LINE_BEGIN) return false;
            if(lhs.inicio == LINE_END)   return true;
        }
           
        if(type == LINE_TYPE && lhs.type == LINE_TYPE){
            if(inicio == LINE_BEGIN) return true;
            else                     return false;
               
        }
           
        return false;
    }
};
   
int s, k, w, h;
   
#define MAX_K 10010
#define MAX_W 10010
   
priority_queue<evt, vector<evt>, greater<evt> > pq;
vector<point> hiding(MAX_K);
vector<pair<point, point> > walls(MAX_W);
   
inline bool cmpActive(const int &a, const int &b){
  if(a == b){
    return false;
  }
   
  if(ccw(walls[a].first-seeker, walls[b].first-seeker) && !ccw(walls[a].second-seeker, walls[b].first-seeker)){
    return ccw(walls[a].second-walls[a].first, walls[b].first-walls[a].first) !=  ccw(walls[a].second-walls[a].first, seeker-walls[a].first);
  }
  else if(ccw(walls[a].first-seeker, walls[b].second-seeker) && !ccw(walls[a].second-seeker, walls[b].second-seeker)){
    return ccw(walls[a].second-walls[a].first, walls[b].second-walls[a].first) !=  ccw(walls[a].second-walls[a].first, seeker-walls[a].first);
  }
  else{// completamente contido no intervalo b
    return ccw(walls[b].second-walls[b].first, walls[a].first-walls[b].first) == ccw(walls[b].second-walls[b].first, seeker-walls[b].first);
  }
}
   
set<int, bool(*)(const int &a, const int &b)> activeLines(cmpActive);

int main(){
      ll ans;
      evt curr;
      while(scanf("%d%d%d",&s,&k,&w) != EOF){
        for (int i = 0; i < k; i++)
            scanf("%lld%lld",&hiding[i].x, &hiding[i].y);
           
        for(int i = 0; i < w; i++)
            scanf("%lld%lld%lld%lld",&walls[i].first.x, &walls[i].first.y, &walls[i].second.x, &walls[i].second.y);
	int tp;
        // for each seeker kid
        for(int i = 0; i < s; i++){
            seeker = hiding[i]; // set up global variable
	    ans = 0;
            activeLines.clear(); // clear active (opened) intervals of line segments
            for(int j = 0; j < w; j++){
                // sort begin-end of an interval by rotation direction( CW or CCW) around seeker
                if(!ccw(walls[j].first-seeker, walls[j].second-seeker)){
                    swap(walls[j].first, walls[j].second);
                }
                  
                // puts segment's ends in a priority queue, sorted by angle wrt the X axis that
                // passes through seeker
                pq.push(evt(walls[j].first,  j, LINE_TYPE, LINE_BEGIN));
                pq.push(evt(walls[j].second, j, LINE_TYPE, LINE_END));
                  
                // if the segment crosses the X axis, put another segment begining in angle=0 (so the angle sort works)
                if(walls[j].first.y < seeker.y &&  walls[j].second.y >= seeker.y){
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
                curr = pq.top(); pq.pop(); // current event
                   
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
		    tp = *activeLines.begin();
                    if(activeLines.empty() || ccw(walls[tp].second-walls[tp].first, curr.p-walls[tp].first) == ccw(walls[tp].second-walls[tp].first, seeker-walls[tp].first)){
                        ans++;
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
}
