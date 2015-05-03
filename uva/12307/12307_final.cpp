#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define EPS 1e-11

using namespace std;
typedef long long ll;
typedef pair<double,double> point;
typedef pair<point, point> line;

ll n;

vector<point> pts, up, dn, chPts;

inline double dist2(point a, point b){ return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);}

inline point toVec(point a, point b){ return point(b.first-a.first,b.second-a.second); }

inline double dot(point a, point b){ return a.first *b.first + a.second * b.second; }

inline double cross(point a, point b){ return a.first * b.second - a.second*b.first; }

inline double cross(point p, point q, point r){	return cross(toVec(p,q),toVec(p,r)); }

inline double norm_sq(point v){ return v.first*v.first + v.second * v.second;}


inline double distToLine(point p, point a, point b, point &c){
	point ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap,ab) / norm_sq(ab);
	c.first  = a.first + ab.first*u;
	c.second = a.second + ab.second*u;
	return sqrt(dist2(p,c));
}

inline double distToLine(point p, point a, point b){
	point dummy;
	return distToLine(p, a, b, dummy);
}

int p[4];
void convexHull(){
	up.assign(n,point()); dn.assign(n,point());
	
	int i = 0, j = 0;
	
	for(int k = 0; k < n; k++){
		while(i > 1 && cross(up[i-2], up[i-1], pts[k]) < EPS) i--;
		while(j > 1 && cross(dn[j-2], dn[j-1], pts[k]) >  -EPS) j--;
		
		up[i++] = pts[k];
		dn[j++] = pts[k];
	}
	p[0] = p[1] = p[2] = p[3] = 0;
	chPts.assign(i+j-2,point());
	for(int k = 0; k < j; k++){
		chPts[k] = dn[k];
	
		if(chPts[p[0]].first > chPts[k].first) p[0] = k;
		if(chPts[p[1]].second > chPts[k].second) p[1] = k;
		if(chPts[p[2]].first < chPts[k].first) p[2] = k;
		if(chPts[p[3]].second < chPts[k].second) p[3] = k;
		
	}
	for(int k = i-2, l = j; k > 0; k--, l++){
		chPts[l] = up[k];
	
		if(chPts[p[0]].first > chPts[l].first) p[0] = l;
		if(chPts[p[1]].second > chPts[l].second) p[1] = l;
		if(chPts[p[2]].first < chPts[l].first) p[2] = l;
		if(chPts[p[3]].second < chPts[l].second) p[3] = l;
	}
}

inline int nxt(int id){ return (id+1)%chPts.size(); }
inline int prev(int id){ return (id == 0 ? (int)chPts.size() : id) - 1;}

inline bool angle_cmp(int lhs, int rhs){
	bool reverse = false;
	if(lhs > rhs){
		reverse = true;
		swap(lhs,rhs);
	}
	bool cmp_res;
	point	pa = toVec(chPts[p[lhs]],chPts[nxt(p[lhs])]),
			pb = toVec(chPts[p[rhs]],chPts[nxt(p[rhs])]);
	
	if(lhs == 0 && rhs == 1) cmp_res = dot	(pa,pb) < -EPS;
	if(lhs == 0 && rhs == 2) cmp_res = cross(pa,pb) < -EPS;
	if(lhs == 0 && rhs == 3) cmp_res = dot	(pa,pb) > EPS;
	if(lhs == 1 && rhs == 2) cmp_res = dot	(pa,pb) < -EPS;
	if(lhs == 1 && rhs == 3) cmp_res = cross(pa,pb) < -EPS;
	if(lhs == 2 && rhs == 3) cmp_res = dot	(pa,pb) < -EPS;
	return cmp_res ^ reverse;
}

// Caliper i defined as vector leaving point p[i] with angles[i]
void rotatingCalipers(){
	
	int p0[4];
	
	for(int i = 0; i < 4; i++)
		p0[i] = p[(i+2)%4];
	
	double ansAr = (chPts[p[2]].first - chPts[p[0]].first)*(chPts[p[3]].second - chPts[p[1]].second), ansPer = 2*((chPts[p[2]].first - chPts[p[0]].first)+(chPts[p[3]].second - chPts[p[1]].second)), l1, l2;
	while(1){
		int incr = -1, ia, ib, ic, id, ie;
		for(int i = 0; i < 4; i++){
			if(incr == -1 || angle_cmp(i,incr)){
				incr = i;
			}
		}
		if(incr == -1 || p[incr] == p0[incr]) break;
		// ia e ib: segmento
		ia = p[incr];
		ib = p[incr] = nxt(p[incr]);
		// ic e id: segundo lado
		ic = p[(incr+1)%4];
		id = p[(incr+3)%4];
		// ie: ponto oposto ao segmento
		ie = p[(incr+2)%4];
		
		l1 = distToLine(chPts[ie],chPts[ia],chPts[ib]);
		
		point pc, pd;
		distToLine(chPts[ic], chPts[ia],chPts[ib], pc);
		distToLine(chPts[id], chPts[ia],chPts[ib], pd);
		l2 = sqrt(dist2(pc,pd));
	
		ansAr = min(ansAr, l1*l2);
		ansPer = min(ansPer,2*(l1+l2));
	}
	cout << fixed << setprecision(2) << ansAr << ' ' << ansPer << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n){
		if(n == 0) break;
		pts.assign(n,point());
		for(int i = 0; i < n; i++){
			cin >> pts[i].first >> pts[i].second;
		}
		
		sort(pts.begin(), pts.end());
		
		convexHull();
		
		rotatingCalipers();
	}
}
