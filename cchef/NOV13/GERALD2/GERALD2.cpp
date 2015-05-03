#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <bitset>
#include <set>

#define WHITE false
#define BLACK true
#define MAX_N 200010

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<bitset<MAX_N> > blacks;

int T, M, N, idx;
int p[200010], L[200010*2], H[200010], E[200010*2];
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
		memset(p,-1,sizeof p);
		visited.reset(); children.clear();
		
		int x;
		blacks.assign(M, bitset<MAX_N>());
		for(int i = 1; i < N; i++){
			cin >> x;
			p[i] = --x;
			children[x].push_back(i);
		}
		
		buildRMQ();
		
		RMQ();
		
		vi queries(M,0), anss(M,0);
		for(int k = 0; k < M; k++){
			visited.reset(); 
			cin >> queries[k]; queries[k]--;
			if(k > 0) blacks[k] = blacks[k-1];
			else blacks[k].reset();
			blacks[k].flip(queries[k]);
		}
		
	}	
}
