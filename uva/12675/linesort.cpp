#include <bits/stdc++.h>

using namespace std;

#define PI 1.157079632679
#define EPS 1e-7

using namespace std;
typedef long long ll;

struct point{
	ll x, y;
	point(){}
	point (int _x, int _y){x = _x; y = _y;}
	bool operator==(point other) const{ return x == other.x && y == other.y; }
	point operator+(point other) const{ return point(x+other.x, y+other.y); }
	point operator-(point other) const{ return point(x-other.x, y-other.y); }
};

point ax(1,0), ay(0,1);

point seeker;

typedef point vec;

inline vec toVec(point a, point b){ return vec(b.x - a.x, b.y - a.y);}

inline ll cross(vec a, vec b){ return a.x*b.y - b.x*a.y; }

inline ll cross(point o, point a, point b){ return cross(toVec(o,a),toVec(o,b)); }

inline bool ccw(point o, point a, point b){ return cross(toVec(o,a),toVec(o,b)) > 0; }

inline int quadrant(point o, point a){
    point a1 = a-o;
    if(a1.x > 0 && a1.y >= 0) return 0;
    if(a1.x <= 0 && a1.y > 0) return 1;
    if(a1.x < 0 && a1.y <= 0) return 2;
    if(a1.x >= 0 && a1.y < 0) return 3;
    return 0;
}

#define LINE_TYPE	0
#define KID_TYPE	1
#define LINE_BEGIN	0
#define LINE_END	1

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
			if(inicio == LINE_END) 	 return true;
		}
		
		if(type == KID_TYPE && lhs.type == LINE_TYPE){
			if(lhs.inicio == LINE_BEGIN) return true;
			if(lhs.inicio == LINE_END) 	 return false;
		}
		
		if(type == LINE_TYPE && lhs.type == LINE_TYPE){
			if(inicio == LINE_BEGIN) return false;
			else 					 return true;
			
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
//~ 
inline bool cmpActive(int a, int b){
  cout << a << ' ' << b << ':';
  if(a == b){
    cout << "false.\n";
    return false;
  }
  bool result;
  if(ccw(seeker, walls[a].first, walls[b].first) && !ccw(seeker, walls[a].second, walls[b].first)){
    cout << '.';
    result = ccw(walls[a].first, walls[a].second, walls[b].first) !=  ccw(walls[a].first, walls[a].second, seeker);
  }
  else if(ccw(seeker, walls[a].first, walls[b].second) && !ccw(seeker, walls[a].second, walls[b].second)){
    result = ccw(walls[a].first, walls[a].second, walls[b].second) !=  ccw(walls[a].first, walls[a].second, seeker);
  }
  else{// completamente contido no intervalo b
    result = ccw(walls[b].first, walls[b].second, walls[a].first) == ccw(walls[b].first, walls[b].second, seeker);
    cout << '!';
  }
  
  cout << (result ? "true\n" : "false\n");
  return result;
}
//~ inline bool cmpActive(int a, int b){
  //~ cout << a << ' ' << b << ':';
  //~ if(a == b){
    //~ cout << "false\n";
    //~ return false;
  //~ }
  //~ bool result;
  //~ if(ccw(seeker, walls[a].first, walls[b].first) && !ccw(seeker, walls[a].second, walls[b].first)){
    //~ result = ccw(walls[a].first, walls[a].second, walls[b].first) !=  ccw(walls[a].first, walls[a].second, seeker);
  //~ }
  //~ else{
    //~ result = ccw(walls[a].first, walls[a].second, walls[b].second) !=  ccw(walls[a].first, walls[a].second, seeker);
  //~ }
  //~ 
  //~ cout << (result ? "true\n" : "false\n");
  //~ return result;
//~ }
set<int, bool(*)(int a, int b)> activeLines(cmpActive);
set<int>::const_iterator it;
vector<int> wo;
int main(){
  int n;
  while(cin >> n){
    walls.assign(n,pair<point,point>());
    seeker = point(153512,-786941);
    wo.assign(n,0);
    for(int i = 0; i < n; i++){
      wo[i] = i;
      cin >> walls[i].first.x >> walls[i].first.y;
      cin >> walls[i].second.x >> walls[i].second.y;
    }
    sort(wo.begin(),wo.end(), cmpActive);
    for(int i = 0; i < wo.size(); i++) cout << wo[i] << ' ';
    cout << endl;
  }
}
