#include <bits/stdc++.h>

#define pb push_back
#define sz size
#define MAXN 200001

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii AdjList, ch;
vi visited, ans;
int memo[MAXN][2], bst;

void root(int u){
  visited[u] = 1;
  int cnt = 0;
  for(size_t i = 0; i < AdjList[u].sz(); i++){
    ii e = AdjList[u][i];
    if(!visited[e.first]){
      cnt++;
      ch[u].pb(e);
      root(e.first);
    }
  }
}


int dp(int u, bool get){
  if(memo[u][get] != -1) return memo[u][get];
  if(ch[u].sz() == 0) return memo[u][get] = 0;
  int aux = 0;
  for(size_t i = 0; i < ch[u].sz(); i++)
    aux += dp(ch[u][i].first,0) + ch[u][i].second;
  if(!get){
    memo[u][get] = aux;
  }
  else{
    memo[u][get] = aux; // root in u
    for(size_t i = 0; i < ch[u].sz(); i++){
      ii e = ch[u][i];
      memo[u][get] = min(memo[u][get], aux - (dp(e.first,0) + e.second) + dp(e.first,1) + !e.second);
    }
  }
  return memo[u][get];
}

void check(int u, int cst){
  int aux = 0;
  for(size_t i = 0; i < ch[u].sz(); i++){
    aux += memo[ch[u][i].first][0] + ch[u][i].second;
  }
  //~ cout << u << &#39; &#39; << cst + aux << &#39; &#39; << aux << &#39;\n&#39;;
  if(cst + aux == bst) ans.pb(u);
  for(size_t i = 0; i < ch[u].sz(); i++){
    ii e = ch[u][i];
    check(e.first, cst + aux - (memo[e.first][0] + e.second) + !e.second);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n){
    AdjList.assign(n, vii());
    int a, b;
    for(int i = 0; i < n-1; i++){
      cin >> a >> b;
      --a, --b;
      AdjList[a].pb(ii(b,0));
      AdjList[b].pb(ii(a,1));
    }
    visited.assign(n,0);
    
    ch.assign(n,vii());
    
    root(0);
    
    memset(memo, -1, sizeof memo);
    
    bst = dp(0,1);
    cout << bst << &#39;\n&#39;;
    ans.clear();
    check(0,0);
    sort(ans.begin(), ans.end());
    cout << ans[0] + 1;
    for(size_t i = 1; i < ans.sz(); i++)
      cout << &#39; &#39; << ans[i] + 1;
    cout << &#39;\n&#39;;
  }
}
