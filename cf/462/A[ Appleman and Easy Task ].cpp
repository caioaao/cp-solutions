#include <bits/stdc++.h>

using namespace std;

char mapa[200][200];

int n;

bool ok(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < n;
}

int dr[4] = {0,0,1,-1},
    dc[4] = {1,-1,0,0};

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> mapa[i][j];
  int i, j, k;
  int amt;
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++){
      amt = 0;
      for(k = 0; k < 4; k++)
        if(ok(i+dr[k],j+dc[k]) && mapa[i+dr[k]][j+dc[k]] == &#39;o&#39;) amt++;
      if(amt&1) goto fim;
      //~ cout << amt << &#39;\n&#39;;
    }
  fim:
  if(i == n && j == n)cout << "YES\n";
  else cout << "NO\n";
  
}
