#include <iostream>
#include <vector>

#define EPS 1e-9
using namespace std;

struct point{
	double x, y;
	point(){x = y = 0;}
	point(double _x, double _y){
		x = _x;
		y = _y;
	}
};

struct line{
	point pa, pb;
	int id;
	line(point a, point b, int _id){
		id = _id;
		pa = a;
		pb = b;
	}
	
	line(){
		;
	}
	
	bool operator<(line rhs){
		return id < rhs.id;
	}
};

point toVec(point a, point b){
	return point(b.x-a.x,b.y-a.y);
}

double cross(point a, point b){
	return a.x*b.y - a.y*b.x;
}

bool ccw(point o, point a, point b){
	return cross(toVec(o,a),toVec(o,b)) > EPS;
}

bool intersect(line a, line b){
	int	 o1 = ccw(a.pa, a.pb, b.pa),
		 o2 = ccw(a.pa, a.pb, b.pb),
		 o3 = ccw(b.pa, b.pb, a.pa),
		 o4 = ccw(b.pa, b.pb, a.pb);
		 
	if(o1 != o2 && o3 != o4) return true;
	return false;
}

vector<line> lines;
vector<bool> hasTop;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	while(cin >> n, n != 0){
		lines.assign(n,line());
		hasTop.assign(n,false);
		for (int i = 0; i < n; i++)
		{
			cin >> lines[i].pa.x >> lines[i].pa.y >> lines[i].pb.x >> lines[i].pb.y;
		}
		
		for (int i = n-1; i >= 0; i--)
		{
			if(hasTop[i]) continue;
			for(int j = n-1; j > i; j--)
			{
				if(intersect(lines[i],lines[j])){
					hasTop[i] = true;
					break;
				}
			}
		}
		cout << "Top sticks: ";
		bool first = true;
		for (int i = 0; i < n; i++)
		{
			if(!hasTop[i]){
				if(!first) cout << ", ";
				first = false;
				cout << i+1;
			}
		}
		cout << ".\n";
		
		
	}
}
