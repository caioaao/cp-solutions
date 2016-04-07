#include <bits/stdc++.h>

#define MAX_N 2001

using namespace std;

int amtU[MAX_N][MAX_N],amtR[MAX_N][MAX_N],amtL[MAX_N][MAX_N];

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n,m,k;
  char auxc;
  while(cin >> n >> m >> k){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> auxc;
        amtU[i][j] = amtL[i][j] = amtR[i][j] = 0;
        if(auxc == &#39;U&#39;) amtU[i][j] = 1;
        else if(auxc == &#39;L&#39;) amtL[i][j] = 1;
        else if(auxc == &#39;R&#39;) amtR[i][j] = 1;
      }
    }
    
    int amt;
    for(int c = 0; c < m; c++){
      amt = 0;
      for(int r = 1; r < n; r++){
        if(r + r < n) amt+= amtU[r + r][c];
        if(c + r < m) amt += amtL[r][c+r];
        if(c - r >= 0) amt += amtR[r][c-r];
      }
      if(c != 0) cout << &#39; &#39;;
      cout << amt;
    }
    cout << &#39;\n&#39;;
  }
}
