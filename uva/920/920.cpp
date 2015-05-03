#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point{
	int x, y;
	point(){;}
	point(int _x, int _y){
		x = _x;
		y = _y;
	}
	bool operator< (const point rhs) const{
		return x < rhs.x;
	}
};
inline point toVec(point a, point b){ return point(b.x - a.x, b.y - a.y); }

inline double dist(point a, point b){ return hypot(a.x-b.x,a.y-b.y);}

vector<point> pts;

int main(){
	ios_base::sync_with_stdio(false);
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		pts.assign(n,point());
		for (int i = 0; i < n; i++)
		{
			cin >> pts[i].x >> pts[i].y;
		}
		
		sort(pts.begin(), pts.end());
		
		double ans = 0, lastH = pts[n-1].y, aux;
		for (int i = n-1; i >= 0; i--)
		{
			if(lastH >= pts[i].y)
				continue;
			
			// Congruencia de triangulos
			aux = dist(pts[i],pts[i+1]);
			
			ans += (pts[i].y - lastH) * aux / (pts[i].y - pts[i+1].y);
			//~ cout << lastH << ' ' << pts[i].x << ',' << pts[i].y << " - " << pts[i+1].x << ',' << pts[i+1].y << ':' << ans << endl;
			lastH = pts[i].y;
		}
		cout << fixed << setprecision(2) << ans << '\n';
	}
}
