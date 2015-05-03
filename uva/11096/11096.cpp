#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

struct point{
	ll x, y;
	point(){;}
	point(ll _x, ll _y){
		x = _x; y = _y;
	}
	bool operator< (const point rhs) const{
		if(x < rhs.x) return true;
		if(x > rhs.x) return false;
		return y < rhs.y;
	}
};

ll cross(point a, point b){
	return a.x*b.y - a.y*b.x;
}

point toVec(point a, point b){ return point(b.x-a.x,b.y-a.y); }

bool ccw(point o, point a, point b)
{
	return cross(toVec(o,a),toVec(o,b)) > 0;
}

vector<point> points, ch, up, dn;

void convexHull()
{
	sort(points.begin(), points.end());
	
	up.assign(points.size(),point());
	dn.assign(points.size(),point());
	
	int i = 0, j = 0;
	for (int k = 0; k < (int)points.size(); k++)
	{
		while(i > 1 && ccw(up[i-2],up[i-1],points[k])) i--;
		while(j > 1 && !ccw(dn[j-2],dn[j-1],points[k])) j--;
		
		up[i++] = dn[j++] = points[k];
	}
	
	ch.clear();
	for(int k = 0; k < i; k++) ch.push_back(up[k]);
	for(int k = j-2; k > 0; k--) ch.push_back(dn[k]);
}

double dist(point a, point b){
	return hypot(a.x-b.x,a.y-b.y);
}

int main(){
	ios_base::sync_with_stdio(false);
	int t, n, tam_inicial;
	cin >> t;
	while(t--){
		cin >> tam_inicial >> n ;
		points.assign(n,point());
		
		for (int i = 0; i < n; i++)
		{
			cin >> points[i].x >> points[i].y;
		}
		
		
		convexHull();
		double ans = dist(ch[0],ch[ch.size()-1]);
		//~ for (int i = 0; i < ch.size(); i++)
		//~ {
			//~ cout << ch[i].x << ',' << ch[i].y << endl;
		//~ }
		
		for (int i = 0; i < (int)ch.size() - 1; i++)
		{
			ans += dist(ch[i],ch[i+1]);
		}
		cout << fixed << setprecision(5) << max(ans,(double)tam_inicial) << '\n';
	}
}
