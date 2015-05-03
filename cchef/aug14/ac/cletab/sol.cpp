#include <bits/stdc++.h>

using namespace std;

int n, m, tables[500], orders[500], sitting[500], nxt[500][500];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    
    memset(tables,0,sizeof tables);
    memset(sitting,0,sizeof sitting);
    
    for(int i = 0; i < m; i++){
      cin >> orders[i];
    }
    
    for(int i = 0; i < 401; i++){
      nxt[m][i] = m;
    }
    
    for(int i = m-1; i >= 0; i--){
      for(int j = 0; j < 401; j++){
        nxt[i][j] = nxt[i+1][j];
      }
      nxt[i][orders[i]] = i;
    }
    
    int minT, ans = 0;
    for(int i = 0; i < m; i++){
      if(!sitting[orders[i]]){
        ans++;
        minT = 0;
        
        for(int j = 1; j < n; j++)
          if(nxt[i+1][tables[j]] > nxt[i+1][tables[minT]])
            minT = j;
        
        sitting[tables[minT]] = false;
        sitting[orders[i]] = true;
        tables[minT] = orders[i];
      }
    }
    cout << ans << '\n';
  }
}
