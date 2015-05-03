#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

#define T_ADD 0
#define T_QUERY 1
#define T_RM 2

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef set<int, bool(*)(int a, int b)> active_set;

struct point{
	ll x, y;
	point(){ x = y = 0;}
	point(ll _x, ll _y){
		x = _x; y = _y;
	}
	
	bool operator <(const point rhs) const{
		if(x < rhs.x) return true;
		return false;
	}
};

typedef pair<int,point> ip;


struct evt{
	point p;
	int type, segId;
	evt(){
		p = point();
	}
	evt(point _p, int _type, int _segId){
		p = _p; type = _type; segId = _segId;
	}
	bool operator<(const evt rhs) const{
		if(p < rhs.p) return true;
		if(rhs.p < p) return false;
		if(type < rhs.type) return true;
		return false;
	}
};


vector<pair<point,point> > lines;
inline bool line_cmp(const int lhs, const int rhs){
	if(lines[lhs].first.x > lines[rhs].first.x && lines[lhs].first.x < lines[rhs].second.x){
		return (lines[rhs].second.x - lines[rhs].first.x) * (lines[lhs].first.y - lines[rhs].first.y) - (lines[rhs].second.y - lines[rhs].first.y) * (lines[lhs].first.x - lines[rhs].first.x) < 0;
	}
	else if(lines[lhs].first.x < lines[rhs].first.x && lines[lhs].second.x > lines[rhs].first.x){
		return (lines[lhs].second.x - lines[lhs].first.x)*(lines[rhs].first.y - lines[lhs].first.y) - (lines[lhs].second.y - lines[lhs].first.y) * (lines[rhs].first.x - lines[lhs].first.x) > 0;
	}
	return false;
}

int n,c;
vector<evt> evts;
active_set active(line_cmp);
vector<ip> pLines;
vector<ip> pBaloons;

ip getP(int p){
	if(p == pLines[p].first){
		return pLines[p];
	}
	ip pP = getP(pLines[p].first);
	if(pP.second.x == -1){ // stuck no prox
		pLines[p].second.y = pP.second.y;
	}
	else{
		pLines[p] = pP; // not stuck ou stuck nos outros acima
	}
	pLines[p].first = p;
	return pLines[p];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> c){
		lines.assign(n, pair<point,point>());
		evts.assign(n*2+c, evt());
		pLines.assign(n,ip(-1,point(-1,-1)));
		pBaloons.assign(c,ip(-1,point(-1,-1)));
		int i = 0;
		for(; i < n; i++){
			pLines[i].first = i;
			cin >> lines[i].first.x >> lines[i].first.y;
			cin >> lines[i].second.x >> lines[i].second.y;
			if(lines[i].second < lines[i].first) swap(lines[i].first,lines[i].second);
			
			if(lines[i].first.y > lines[i].second.y) pLines[i].second.x = lines[i].first.x;
			else if(lines[i].first.y < lines[i].second.y) pLines[i].second.x = lines[i].second.x;
			else{
				pLines[i].second.x = -1;
				pLines[i].second.y = lines[i].first.y;
			}
			
			evts[i*2].p = lines[i].first;
			evts[i*2].type = T_ADD;
			evts[i*2].segId = i;
			
			evts[i*2+1].p = lines[i].second;
			evts[i*2+1].type = T_RM;
			evts[i*2+1].segId = i;
		}
		i*=2;
		
		for(int k = 0; k < c; k++, i++){
			cin >> evts[i].p.x;
			evts[i].type = T_QUERY;
			evts[i].segId = k;
			pBaloons[k].second.x = evts[i].p.x;
		}
		sort(evts.begin(), evts.end());
		active.clear();
		
		active_set::const_iterator itP;
		for(int k = 0; k < (int)evts.size(); k++){
			if(evts[k].type == T_ADD){
				//~ cout << "Adding line " << evts[k].segId << " in point " << evts[k].p.x << ',' << evts[k].p.y << endl;
				active.insert(evts[k].segId);
				if(lines[evts[k].segId].first.y > lines[evts[k].segId].second.y){
					itP = active.find(evts[k].segId);
					++itP;
					if(itP != active.end()){
						pLines[evts[k].segId].first = *itP;
					}
				}
			}
			else if(evts[k].type == T_RM){
				//~ cout << "Removing line " << evts[k].segId << " in point " << evts[k].p.x << ',' << evts[k].p.y << endl;
				if(lines[evts[k].segId].second.y > lines[evts[k].segId].first.y){
					itP = active.find(evts[k].segId);
					++itP;
					if(itP != active.end())
						pLines[evts[k].segId].first = *itP;
				}
				active.erase(evts[k].segId);
			}
			else if(evts[k].type == T_QUERY){
				//~ cout << "Querying balloon " << evts[k].segId << " in point " << evts[k].p.x << ',' << evts[k].p.y;
				if(active.size() > 0)
					pBaloons[evts[k].segId].first = *(active.begin());
				//~ cout << " getting parent " << pBaloons[evts[k].segId].first << endl;
			}
		}
		
		for(int k = 0; k < c; k++){
			if(pBaloons[k].first == -1) cout << pBaloons[k].second.x << '\n';
			else{
				ip acima = getP(pBaloons[k].first);
				//~ cout << acima.first << ':' << acima.second.x << ',' << acima.second.y << endl;
				cout << (acima.second.x != -1 ? acima.second.x : pBaloons[k].second.x);
				if(acima.second.y != -1) cout << ' ' << acima.second.y;
				cout << '\n';
			}
		}
		
	}
}
