#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>
using namespace std;

#define lli long long int

const double EPS = .000000001;

struct point{
	double x,y;
};

double dist(point a, point b){
	return sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}

double distToLine(point p, point a, point b, point *c){
	double scale = (double)((p.x-a.x)*(b.x-a.x) + (p.y-a.y)*(b.y-a.y)) / ((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
	c->x = a.x + scale * (b.x - a.x);
	c->y = a.y + scale * (b.y - a.y);

	return dist(p,*c);
}

double distToLineSegment(point p, point a, point b, point *c){
	if((b.x-a.x) * (p.x-a.x) + (b.y-a.y) * (p.y-a.y) < EPS){
		c->x = a.x;
		c->y = a.y;
		return dist(p,a);
	}
	if((a.x-b.x) * (p.x-b.x) + (a.y-b.y) * (p.y-b.y) < EPS){
		c->x = b.x;
		c->y = b.y;
		return dist(p,b);
	}
	return distToLine(p,a,b,c);
}

int main(){
	point m;

	while(!(cin  >> m.x >> m.y).eof()){
		point a, b, c, min_c;
		double d, min_d = numeric_limits<double>::infinity();
		int N;

		cin >> N;

		cin >> a.x >> a.y;

		for(int i = 0; i < N; i++){
			b.x = a.x;
			b.y = a.y;

			cin >> a.x >> a.y;
			d = distToLineSegment(m,a,b, &c);
			if(d < min_d){
				min_d = d;
				min_c = c;
			}
			
		}
		printf("%.4lf\n%.4lf\n",min_c.x,min_c.y);
	}
}
