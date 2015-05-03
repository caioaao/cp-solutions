#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii > vii;

vii nodes;
vector<pair<double, ii> > EdgeList;

class UnionFind{
private:
	vi p, rank;
	int counter;
public:
	UnionFind(int N){
		counter = N;
		rank.assign(N,0);
		p.assign(N,0); for(int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
	bool isSameSet(int  i, int j){ return findSet(i) == findSet(j); }
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			counter--;
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else{
				p[x] = y;
				if( rank[x] == rank[y]) rank[y]++;
			}
			
		}
	}
	int count(){ return counter; }
};




double dist(int i, int j){
	return sqrt((nodes[i].first-nodes[j].first)*(nodes[i].first-nodes[j].first)+(nodes[i].second-nodes[j].second)*(nodes[i].second-nodes[j].second));
}

int main(){
	int T, R, N, x, y;
	
	cin >> T;
	
	for(int Ti = 1; Ti <= T; Ti++){
	
		cin >> N >> R;
		
		nodes.assign(N, ii()); EdgeList.clear();
		for(int i = 0; i < N; i++){
			cin >> x >> y;
			
			nodes[i].first = x; nodes[i].second = y;
			for(int j = i-1; j >= 0; j--){
				EdgeList.push_back(make_pair(dist(i,j), ii(j,i)));
			}
		}
		
		sort(EdgeList.begin(),EdgeList.end());
		
		double roads = 0, railroads = 0;
		int states = 1;
		bool fRoad = true;
		UnionFind UF(N);
		for(int i = 0; i < (int)EdgeList.size(); i++){
			pair<double, ii> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				if(front.first > R){
					railroads += front.first;
					if(fRoad){
						states = UF.count();
						fRoad = false;
					}
				}
				else{
					roads+= front.first;
				}
				UF.unionSet(front.second.first, front.second.second);
				if(UF.count() == 1) break;
			}
		}
		
		cout << "Case #" << Ti << ": " << states << ' ' << (int)(roads+.5) << ' ' << (int)(railroads+.5)<<'\n';
	}
}
