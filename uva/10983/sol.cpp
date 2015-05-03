#include <bits/stdc++.h>

#define NN 350
#define INF 0x7fffffff

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

struct edge {
	int x, y, c, c0, r, s;
};

vector<edge> E;
VVI G;

int flow(int s, int t) {
	for (int f = 0;;) {
		VI prev(G.size(), -1);
		queue<int> q;

		q.push(s); prev[s] = 0;
		while (!q.empty() && prev[t] < 0) {
			int x = q.front(); q.pop();
			for (int i = 0; i < (int)G[x].size(); i++) {
				int e = G[x][i], y = E[e].y;
				if (E[e].c == 0 || prev[y] >= 0) continue;
				prev[y] = e;
				q.push(y);
			}
		}

		if (prev[t] < 0)
			return f;

		int c = INF;
		for (int x = t; x != s; x = E[prev[x]].x)
			c = min(c,E[prev[x]].c);

		for (int x = t; x != s; x = E[prev[x]].x) {
			E[prev[x]].c -= c;
			E[E[prev[x]].r].c += c;
		}
		f += c;
	}
}

void add(int x, int y, int c, int s) {
	struct edge e;
	e.x = x; e.y = y; e.c = e.c0 = c; e.s = s;
	e.r = E.size()+1;
	G[x].push_back(E.size());
	E.push_back(e);
	swap(e.x, e.y);
	e.r = E.size()-1;
	e.c = e.c0 = 0;
	G[y].push_back(E.size());
	E.push_back(e);
}

int tot_p, t, caso = 1, dt, m, nn;

int bs(int hi){
  int lo = 0, mi;
  
  while(lo+1 < hi){
    //~ cout << lo << ' ' << hi << endl;
    mi = (lo + hi)/2;
    for(int i = 0; i < (int)E.size(); i++)
      E[i].c = E[i].s <= mi ? E[i].c0 : 0;
    
    if(flow(0,nn*(dt + 1)) < tot_p){
      lo = mi;
    }
    else{
      hi = mi;
    }
  }
  
  for(int i = 0; i < (int)E.size(); i++)
    E[i].c = E[i].s <= lo ? E[i].c0 : 0;
  if(flow(0,nn*(dt + 1)) >= tot_p){
    return lo;
  }
  
  if(lo != hi){
    for(int i = 0; i < (int)E.size(); i++)
      E[i].c = E[i].s <= hi ? E[i].c0 : 0;
    if(flow(0,nn*(dt + 1)) >= tot_p){
      return hi;
    }
  }
  
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> t;
  while(t--){
    cout << "Case #" << caso++ << ": ";
    cin >> nn >> dt >> m;
    E.clear();
    G.assign(nn*(dt+1)+1,VI());
    
    int u, v, c, p, e;
    
    int max_cost = 0;
    for(int i = 0; i < m; i++){
      cin >> u >> v >> c >> p >> e;
      add(u + nn * e, v + nn * (e + 1), c, p);
      max_cost = max(max_cost,p);
    }
    
    for(int i = 0; i < dt; i++){
      for(int j = 1; j <= nn; j++){
        add(j + i*nn, j + (i+1)*nn, INF, 0);
      }
    }
    tot_p = 0;
    int zi;
    for(int i = 1; i <= nn; i++){
      cin >> zi;
      tot_p += zi;
      add(0, i, zi, 0);
    }
    
    int ans = bs(max_cost);
    if(ans != -1)
      cout << ans << '\n';
    else
      cout << "Impossible\n";
  }
}
