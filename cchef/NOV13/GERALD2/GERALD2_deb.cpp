#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <bitset>

#define WHITE false
#define BLACK true

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

bool DEBUG = false;

int T, M, N, idx;
int p[200010], L[200010*2], H[200010], E[200010*2], colors[200010];
map<int, vi> children;
bitset<200010> visited;


void dfs(int cur, int depth){
	H[cur] = idx;
	E[idx] = cur;
	L[idx++] = depth;
	for(int i = 0; i < (int)children[cur].size(); i++){
		dfs(children[cur][i], depth+1);
		E[idx] = cur;
		L[idx++] = depth;
	}
}

inline void buildRMQ(){	
	//Build LCA vectors
	idx = 0;
	memset(H,-1, sizeof H);
	
	dfs(0,0);
}

int SpT[200500][20];
inline void RMQ(){
	for(int i = 0; i < 2*N; i++)
		SpT[i][0] = i;
		
	for(int j = 1; (1<<j) <= 2*N; j++)
		for(int i = 0; i+(1<<j) - 1 < 2*N; i++)
			if(L[SpT[i][j-1]] < L[SpT[i+(1<<(j-1))][j-1]])
				SpT[i][j] = SpT[i][j-1];
			else
				SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
		
	
}
inline int query(int i, int j){
	int k = (int)floor(log((double)j-i+1)/log(2.));
	if(L[SpT[i][k]] <= L[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
	else return SpT[j-(1<<k)+1][k];
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	while(T--){
		cin >> N >> M;
		memset(p,-1,sizeof p); memset(colors, WHITE, sizeof colors);
		visited.reset(); children.clear();
		
		int x;
		for(int i = 1; i < N; i++){
			cin >> x;
			p[i] = --x;
			children[x].push_back(i);
		}
		
//////////////////////////////////////////////
		if(DEBUG){
			for(map<int,vi>::const_iterator it = children.begin(); it != children.end(); ++it){
				cout << it->first <<  ':';
				for(int i = 0; i < (int)it->second.size(); i++)cout << ' ' << it->second[i];
				cout << endl;
			}
		}
//////////////////////////////////////////////
		
		buildRMQ();
		
		RMQ();
		
		int lca, dist, dist1, dist2, ind1, ind2,dMax, ans;
		
//////////////////////////////////////////////
		if(DEBUG){
			for(int i = 0; i < N; i++) cout << H[i] << ' ';
			cout << endl;
			for(int i = 0; i < N*2; i++) cout << E[i] << ' ';
			cout << endl;
			for(int i = 0; i < N*2; i++) cout << L[i] << ' ';
			cout << endl;
			cout << "RMQ(H[4],H[5]): " << query(H[4],H[5]) << endl;
			// break;
		}
//////////////////////////////////////////////
		
		while(M--){
			visited.reset();
			cin >> x; x--;
			bool didIt = false;
			dMax = 0;
			if(colors[x] == BLACK){ colors[x] = WHITE; didIt = true;}
			for(int j = 0; j < N; j++){
				if(colors[j] == BLACK || visited.test(j)) continue;
				visited.set(j);
				dist = dist1 = dist2 = 0; ind1 = x; ind2 = j;
				if(H[ind1] > H[ind2]) swap(ind1,ind2);
				lca = E[query(H[ind1],H[ind2])];
				
///////////////////////////////////////////
				if(DEBUG) cout << "lca(" << x << ',' << j << ") = " << lca << ", dist: ";
///////////////////////////////////////////
				while(1){
					if(ind1 != lca){
						visited.set(ind1);
						dist1++; ind1 = p[ind1];
					}
					if(ind2 != lca){
						visited.set(ind2);
						dist2++; ind2 = p[ind2];
					}
					if(ind1 == lca && ind2 == lca) break;
				}
				dist = dist1+dist2;
//////////////////////////////////////////
				if(DEBUG) cout << dist << endl;
//////////////////////////////////////////
				if(dist >= dMax){
					dMax = dist;
					ans = j;
				}
			}
			if(!didIt) colors[x] = BLACK;
			cout << ans+1 << '\n';
		}
	}	
}
