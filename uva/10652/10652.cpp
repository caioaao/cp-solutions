#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

#define DEG_RAD(x) ((x)*3.14159265359)/180

using namespace std;

struct point{
	double x, y;
	point(){;}
	point(double _x, double _y){
		x = _x;
		y = _y;
	}
	
	bool operator<(const point rhs) const{
		if(x < rhs.x) return true;
		if(x > rhs.x) return false;
		return y < rhs.y;
	}
};

vector<point> pts, ch, up, dn;

point toVec(point a, point b){ return point(b.x - a.x, b.y - a.y); }
double cross(point a, point b){ return (a.x*b.y - a.y*b.x); }
bool ccw(point o, point a, point b){ return cross(toVec(o,a),toVec(o,b)) > 0; }

point rotate(point p, double theta){
	double rad = DEG_RAD(theta);
	
	return point(p.x * cos(rad) - p.y * sin(rad),
				 p.x * sin(rad) + p.y * cos(rad));
}

void convexHull(){
	ch.clear();
	sort(pts.begin(), pts.end());
	int n = pts.size();
	up.assign(n,point());
	dn.assign(n,point());
	int i = 0, j = 0; 
	for(int k = 0; k < n; k++){
		while(i > 1 &&  ccw(up[i-2], up[i-1], pts[k])) i--;
		while(j > 1 && !ccw(dn[j-2], dn[j-1], pts[k])) j--;
		
		up[i++] = pts[k];
		dn[j++] = pts[k];
	}
	
	for(int k = 0; k < i; k++)
		ch.push_back(up[k]);
	for(int k = j-2; k > 0; k--)
		ch.push_back(dn[k]);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int T, n;
	int mw[4] = { 1, 1,-1,-1},
		mh[4] = { 1,-1, 1,-1};
	double w, h, theta, area_pol, area_sqs, dw, dh;
	cin >> T;
	point ctr, aux;
	while(T--){
		cin >> n;
		
		area_sqs = 0;
		pts.clear();
		for(int i = 0; i <  n; i++){
			cin >> ctr.x >> ctr.y >> w >> h >> theta;
			area_sqs += w*h;
			theta = -theta;
			dw = w/2; dh = h/2;
			for(int k = 0; k < 4; k++){
				aux = rotate(point(mw[k]*dw,mh[k]*dh),theta);
				aux.x += ctr.x;
				aux.y += ctr.y;
				pts.push_back(aux);
			}
		}
		convexHull();
		area_pol = 0;
		n = ch.size();
		for(int i = 0; i < n; i++){
			area_pol += ch[i].x*ch[(i+1)%n].y - ch[(i+1)%n].x*ch[i].y;
		}
		area_pol = fabs(area_pol/2);
		
		//~ cout << area_sqs << ' ' << area_pol << endl;
		cout << fixed << setprecision(1) << (area_sqs*100) / area_pol << " %\n";
	}
}
