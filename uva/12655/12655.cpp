#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>

#define MAX_N 20010
#define MLOGN 30

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<pll> vpll;

vector<vpll> AdjList, child;
vector<plll> EdgeList;
vector<int> visited;


int n,m,s;

int SpT[MAX_N*2][MLOGN], L[MAX_N*2], H[MAX_N], E[MAX_N*2], idx;
void buildSparseTable() {
  for (int i = 0; i < idx; i++)
    SpT[i][0] = i; 
    
  for (int j = 1; (1<<j) <= idx; j++) 
    for (int i = 0; i + (1<<j) - 1 < idx; i++)    
      if (L[SpT[i][j-1]] < L[SpT[i+(1<<(j-1))][j-1]])            
        SpT[i][j] = SpT[i][j-1];    
      else                 
        SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
}

int queryLCA(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    if (L[SpT[i][k]] <= L[SpT[j-(1<<k)+1][k]])
      return SpT[i][k];
    else
      return SpT[j-(1<<k)+1][k];
}

void dfs_lca(int cur, int depth){
	H[cur] = idx;
	E[idx] = cur;
	L[idx++] = depth;
	for(int i = 0; i < (int)child[cur].size(); i++){
		dfs_lca(child[cur][i].first, depth+1);
		E[idx] = cur;
		L[idx++] = depth;
	}
}

void buildLCA(){
	idx = 0;
	memset(H,-1, sizeof H);
	dfs_lca(0,0);
	buildSparseTable();
}

pll t[MAX_N][MLOGN];
void precomputa(){
	for(int u = 0; u < n; u++){
		for(int j = 0; j < (int)child[u].size(); j++){
			pll v = child[u][j];
			t[v.first][0].first = u;
			t[v.first][0].second = v.second;
		}
	}
	
	int i, j, aux;
	for(j = 1; (1<<j) <= n; j++){
		for(i = 0; i < n; i++){
			aux = t[i][j-1].first;
			t[i][j].first = t[aux][j-1].first;
			t[i][j].second = min(t[i][j-1].second,t[aux][j-1].second);
		}
	}
	
	//~ for(int i = 0; i < n; i++, cout << '\n')
		//~ for(int j = 0; (1<<j) <= n; j++) cout << '(' << t[i][j].first << ',' << t[i][j].second << ") ";
}

// Computa a menor aresta entre a e b, contando que um deles seja o pai
// do outro
int menor_aresta(int a, int b){
	if(L[H[a]] < L[H[b]]) swap(a,b); // b eh pai de a (L eh profundida-
									 // de do no, se usar LCA do CP3)
	ll ans = 1e9;
	for(int i = MLOGN-1; i >= 0 && a != b; i--){
		//~ cout << a << "!=" << b << ',' << L[H[a]] << '-' << L[H[b]] << ':'<< logH << endl;
		if(L[H[b]] <= L[H[a]] - (1 << i)){
			ans = min(ans, t[a][i].second);
			//~ if(t[a][logH].second == 0) cout << "t[" << a << "][" << logH << "] = 0" << endl;
			a = t[a][i].first;
		}
	}
	return ans;
}


vector<int> pUF;
ll amtSets;

void UnionFind(){
	pUF.assign(n,0);
	for(int i = 0; i < n; i++) pUF[i] = i;
	amtSets = n;
}
int findSet(int a){ return pUF[a] = (a == pUF[a] ? a : findSet(pUF[a]));}
bool isSameSet(int a, int b){ return (findSet(a) == findSet(b));}
void unionSet(int a, int b){
	if(isSameSet(a,b)) return ;
	
	pUF[findSet(a)] = findSet(b);
	amtSets--;
}

queue<int> q;
void kruskal(){
	sort(EdgeList.begin(), EdgeList.end(), greater<plll>());
	UnionFind();
	AdjList.assign(n,vpll());
	
	for(int i = 0; i < m && amtSets > 1; i++){
		if(!isSameSet(EdgeList[i].second.first, EdgeList[i].second.second)){
			AdjList[EdgeList[i].second.first].push_back(pll(EdgeList[i].second.second,EdgeList[i].first));
			AdjList[EdgeList[i].second.second].push_back(pll(EdgeList[i].second.first,EdgeList[i].first));
			unionSet(EdgeList[i].second.first,EdgeList[i].second.second);
		}
	}
	
	// Root tree in 0
	visited.assign(n,0);
	child.assign(n,vpll());
	q.push(0);
	int u;
	pll v;
	while(!q.empty()){
		u = q.front(); q.pop();
		visited[u] = true;
		for(int j = 0; j < (int)AdjList[u].size(); j++){
			v =AdjList[u][j]; 
			if(!visited[v.first]){
				q.push(v.first);
				child[u].push_back(v);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> m >> s){
		EdgeList.assign(m, plll());
		for(int i = 0; i < m; i++){
			cin >> EdgeList[i].second.first >> EdgeList[i].second.second >> EdgeList[i].first;
			EdgeList[i].second.first--;
			EdgeList[i].second.second--;
		}
		
		kruskal();
		buildLCA();
		precomputa();
		int a, b, lca, ans;
		int zeros = 0;
		for(int i = 0; i < s; i++){
			cin >> a >> b;
			a--;b--;
			if(H[a] > H[b]) swap(a,b);
			lca = E[queryLCA(H[a],H[b])];
			ans = min(menor_aresta(a,lca),menor_aresta(b,lca));
			if(lca == 0) zeros++;
			//~ if(ans == 68239){
				//~ cout << "LCA entre " << a << " e " << b << ": " << lca << ',';
			//~ }
			cout << ans << '\n';
		}
		//~ cout << zeros << " de " << s << endl;
		//~ for(int i = 0; i < child[0].size(); i++) cout << child[0][i].first << ' ' << child[0][i].second << endl;
	}
}
