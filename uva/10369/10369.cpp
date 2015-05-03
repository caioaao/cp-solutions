#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

viii EdgeList;
vii posts;
vi p;

int S, V, nSets;

void unionConstruct(){nSets = V; p.assign(V,0); for(int i = 0; i < V; i++) p[i] = i;}
int findSet(int a){return (a == p[a] ? a : findSet(p[a]));}
bool isSameSet(int a, int b){return findSet(a) == findSet(b);}
void unionSets(int a, int b){
	if(!isSameSet(a,b)){
		nSets--;
		p[findSet(a)] = findSet(b);
	}
}

int dist2(ii a, ii b){
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> S >> V;
		EdgeList.clear(); posts.assign(V, ii(0,0));
		unionConstruct();
		
		for(int i = 0; i < V; i++){
			cin >> posts[i].first >> posts[i].second;
			for(int j = 0; j < i; j++) EdgeList.push_back(iii(dist2(posts[i],posts[j]),ii(i,j)));
		}
		
		int ans = 0;
		sort(EdgeList.begin(), EdgeList.end());
		for(int i = 0; i < (int)EdgeList.size() && nSets > S; i++){
			int u = EdgeList[i].second.first, v = EdgeList[i].second.second, w = EdgeList[i].first;
			if(!isSameSet(u,v)){
				unionSets(u,v);
				ans = w;
			}
		}
		cout << fixed << setprecision(2) << sqrt(ans) << '\n';
		
	}
}
