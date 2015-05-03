#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

struct point{
	ll x, y;
	point(){;}
	point(ll _x, ll _y){
		x = _x;
		y = _y;
	}
	
	bool operator<(const point rhs) const{
		if(x < rhs.x) return true;
		if(x > rhs.x) return false;
		return y < rhs.y;
	}
};
inline point toVec(point a, point b){ return point(b.x-a.x, b.y-a.y); }
inline ll dist2(point a, point b){ return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);}
inline ll cross(point a, point b){ return a.x*b.y - a.y*b.x; }


struct pole{
	point p;
	int h;
	pole(){;}
	pole(ll x, ll y, int _h){
		p.x = x;
		p.y = y;
		h = _h;
	}
	bool operator<(const pole rhs) const{
		return dist2(p,point(0,0)) < dist2(rhs.p,point(0,0));
	}
};

typedef set<pole, bool(*)(pole lhs, pole rhs)> sp;

inline bool cmp(pole lhs, pole rhs){
	
	if(cross(lhs.p,rhs.p) < 0) // CW
	{
		return false;
	}
	else if(cross(lhs.p,rhs.p) > 0)// CCW
	{
		return true;
	}
	return false;
}

vector<pole> pos, negs;
vector<point> ans;
sp alinhados(cmp);

void solve(vector<pole> &poles){
	alinhados.clear();
	
	sort(poles.begin(),poles.end());
	sp::iterator it;
	for(int i = 0; i < (int)poles.size(); i++)
	{
		it = alinhados.find(poles[i]);
		
		if(it != alinhados.end()){
			//~ cout << it->h << endl;
			if(it->h >= poles[i].h)
			{
				ans.push_back(poles[i].p);
			}
			else
			{
				alinhados.erase(*it);
				alinhados.insert(poles[i]);
			}
		}
		else
			alinhados.insert(poles[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, ds = 1;
	pole aux;
	while(cin >> n, n!=0){
		cout << "Data set " << ds++ << ":\n";
		pos.clear();
		negs.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> aux.p.x >> aux.p.y >> aux.h;
			if(aux.p.x>=0) pos.push_back(aux);
			else{
				negs.push_back(aux);
			}
		}
		ans.clear();
		
		solve(pos);
		solve(negs);
		if(ans.size()){
			cout << "Some lights are not visible:\n";
			sort(ans.begin(), ans.end());
			bool first = true;
			for(int i = 0; i < (int)ans.size(); i++){
				if(!first) cout << ";\n";
				first = false;
				cout << "x = " << ans[i].x << ", y = " << ans[i].y;
			}
			cout << ".\n";
		}
		else{
			cout << "All the lights are visible.\n";
		}
	}
}
