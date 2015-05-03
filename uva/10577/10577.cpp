#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

struct point{
	double x,y;
	
	point(){;}
	point(double _x, double _y){
		x = _x;
		y = _y;
	}
};


inline point circumcenter(point a, point b, point c)
{
	double d = 2.*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
	
	return point(((a.x*a.x + a.y*a.y)*(b.y - c.y) + (b.x*b.x + b.y*b.y)*(c.y - a.y) + (c.x*c.x + c.y*c.y) * (a.y - b.y))/d,
				  ((a.x*a.x + a.y*a.y)*(c.x - b.x) + (b.x*b.x + b.y*b.y)*(a.x - c.x) + (c.x*c.x + c.y*c.y) * (b.x - a.x))/d);
}

inline point rotate(point p, double rad)
{
	return	 point(p.x * cos(rad) - p.y * sin(rad),
					p.x * sin(rad) + p.y * cos(rad));
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, poligono = 1;
	point pts[3], pt, center;
	double minX, minY, maxX, maxY;
	while(cin >> n, n != 0)
	{
		cout << "Polygon " << poligono++ << ": ";
		
		for(int i = 0; i < 3; i++) cin >> pts[i].x >> pts[i].y;
		
		center = circumcenter(pts[0], pts[1], pts[2]);
		
		pt = point(pts[0].x - center.x, pts[0].y - center.y);
		minX = maxX = minY = maxY = 0.0;
		double d_ang = 2.*PI/n;
		while(n--){
			minX = min(minX,pt.x);
			maxX = max(maxX,pt.x);
			minY = min(minY,pt.y);
			maxY = max(maxY,pt.y);
			pt = rotate(pt,d_ang);
		}
		
		double ans = (maxX - minX)*(maxY - minY);
		cout << fixed << setprecision(3) << ans << '\n';
	}
}
