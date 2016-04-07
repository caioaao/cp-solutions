#include <bits/stdc++.h>

#define MAX_N 100
 
using namespace std;

char mapa[MAX_N][MAX_N];
int colors[MAX_N][MAX_N];

int n, m;

int dr[4] = { 0, 1, 0,-1},
    dc[4] = { 1, 0,-1, 0};

inline bool valid(int r, int c){
  return r < n && c < m && r >= 0 && c >= 0 && mapa[r][c] == &#39;.&#39;;
}

void ffill(int r, int c, bool cor){
  colors[r][c] = cor;
  int rf,cf;
  for(int i = 0; i < 4; i++){
    rf = r+dr[i];
    cf = c+dc[i];
    if(valid(rf,cf) && colors[rf][cf] == -1){
      ffill(rf, cf, !cor);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> n >> m){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	cin >> mapa[i][j];
	colors[i][j] = -1;
      }
    }
    
    for(int i  = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	if(colors[i][j] == -1 && mapa[i][j] == &#39;.&#39;) ffill(i,j,0);
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	if(colors[i][j] == 0) cout << &#39;B&#39;;
	else if(colors[i][j] == 1) cout << &#39;W&#39;;
	else cout << mapa[i][j];
      }
      cout << &#39;\n&#39;;
    }
  }
}
