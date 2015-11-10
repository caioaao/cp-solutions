#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,int> point;
typedef long long ll;

int n;
vector<point> pts, up, dn;

/////////////////
// Geom funcs
/////////////////

inline ll dist2(point a, point b){ return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);}

inline point toVec(point a, point b){ return point(b.first-a.first,b.second-a.second); }

inline ll dot(point a, point b){ return a.first *b.first + a.second * b.second; }

inline ll norm_sq(point v){ return v.first*v.first + v.second * v.second;}

inline double distToLine(point p, point a, point b){
	point c;
	point ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap,ab) / (double)norm_sq(ab);
	double x = (double)a.first + ab.first*u, y =  (double)a.second + ab.second*u;
	return sqrt(((double)p.first - x)*((double)p.first - x) + ((double)p.second - y)*((double)p.second - y));
}


inline ll cross(point oa, point ob){
	return oa.first*ob.second - oa.second*ob.first;
}

inline bool ccw(point o, point a, point b){
	return cross(toVec(o,a), toVec(o,b)) > 0;
}



vector<point>chPts;
void convexHull(){
	sort(pts.begin(),pts.end());

	up.assign(n,point());
	dn.assign(n,point());

	int i = 0, j = 0;

	for(int k = 0; k < n; k++){
		while(i > 1 && ccw(up[i-2],up[i-1],pts[k])) i--;
		while(j > 1 && !ccw(dn[j-2],dn[j-1],pts[k])) j--;

		up[i++] = pts[k];
		dn[j++] = pts[k];
	}
	up.resize(i);
	dn.resize(j);
	chPts = up;
	for(int i = (int)dn.size() -  2; i >= 0; i--) chPts.push_back(dn[i]);
}

double rotatingCalipers() {
// comparacao dos pares antipodais sempre testa quando encontra uma
// aresta em que os 2 pontos são antipodais com o terceiro ponto
// (ideia básica do minimum enclosing rectangles
	double best = 1e8;

	int i = 0, j = dn.size() - 1;

	while(i < (int) up.size() - 1 || j > 0) {
		if(i == (int) up.size() - 1) {
			j--;
			best = min(best, distToLine(up[i],dn[j],dn[j+1]));
		}
		else if(j == 0){
			i++;
			best = min(best, distToLine(dn[j],up[i],up[i-1]));
		}
		else{
			if(ccw(point(0,0), toVec(up[i], up[i+1]), toVec(dn[j],dn[j-1]))){
				i++;
				best = min(best, distToLine(dn[j],up[i],up[i-1]));
			}
			else{
				j--;
				best = min(best, distToLine(up[i],dn[j],dn[j+1]));
			}
		}
	}

	return best;
}


int main(){
	ios_base::sync_with_stdio(false);
	int caso = 1;
	bool first = true;
	while(cin >> n){
		if(!first) cout  << '\n';
		first = false;

		if(n == 0) break;

		cout << "Case " << caso++ << ": ";

		pts.assign(n,point());

		for(int i = 0; i < n; i++){
			cin >> pts[i].first >> pts[i].second;
		}

		convexHull();

		cout << fixed << setprecision(2) << rotatingCalipers();
	}
}
