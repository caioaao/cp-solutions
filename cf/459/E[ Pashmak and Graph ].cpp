#include <bits/stdc++.h>

#define MAX_N 300001

using namespace std;
typedef vector<int> vi;

vector<vi> adj;
int n, m;

int dpk[MAX_N][2], dpv[MAX_N][2], w[MAX_N], a[MAX_N], b[MAX_N], ord[MAX_N];

bool cmp(int u, int v){
  return w[u] > w[v];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  adj.assign(n,vi());
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> w[i];
    a[i]--;b[i]--;
    ord[i] = i;
    adj[a[i]].push_back(i);
  }
  
  //~ for(int i = 0; i < n; i++){
    //~ cout << "adj[" << i << "]: {";
    //~ for(int j = 0; j < adj[i].size(); j++) cout << b[adj[i][j]] << &#39;,&#39;;
    //~ cout << "}\n";
  //~ }
  memset(dpv, 0, sizeof dpv);
  
  sort(ord, ord+m, cmp);
  int u, aux, ans = 1;
  for(int i = 0; i < m; i++){
    u = ord[i];
    aux = 1;
    if(dpk[b[u]][0] > w[u]){
      aux = dpv[b[u]][0] + 1;
    }
    else{
      aux = dpv[b[u]][1] + 1; // maior que o primeiro
    }
    if(dpv[a[u]][0] < aux){
      if(dpk[a[u]][0] > w[u]){
	dpk[a[u]][1] = dpk[a[u]][0];
	dpv[a[u]][1] = dpv[a[u]][0];
      }
      dpk[a[u]][0] = w[u];
      dpv[a[u]][0] = aux;
    }
    
    ans = max(ans, dpv[a[u]][0]);
  }
  
  cout << ans << &#39;\n&#39;;
}
