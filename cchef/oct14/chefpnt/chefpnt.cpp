#include <bits/stdc++.h>

#define MAXN 101
#define MAGIC 2017

using namespace std;

vector<int> xa,ya,da;

int mp[MAXN][MAXN], amtx[MAXN], amty[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  
  int n,m,k;
  while(cin >> n >> m >> k){
    int x,y;
    memset(mp,0,sizeof mp);
    memset(amtx,0,sizeof amtx);
    memset(amty,0,sizeof amty);
    for(int i = 0; i < k; i++){
      cin >> x >> y;
      x--;y--;
      amtx[x]++;  
      amty[y]++;
      mp[x][y] = 1;
    }
    xa.clear();
    ya.clear();
    da.clear();
    
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    if(mp[i][j] == 0){
        bool dir = ((amtx[i]+amty[j])*MAGIC)&1;
        xa.push_back(i+1);
        ya.push_back(j+1);
        da.push_back(dir);
        
        if(!dir){
          for(int k = j; k >= 0 && !mp[i][k]; k--)
            mp[i][k] = 1;
          for(int k = j+1; k < m && !mp[i][k]; k++)
            mp[i][k] = 1;
          }
        else{
          for(int k = i; k >= 0 && !mp[k][j]; k--)
            mp[k][j] = 1;
          for(int k = i+1; k <n && !mp[k][j]; k++)
            mp[k][j] = 1;
        }
      }
    
    //for(int i = 0; i < n; i++, cout << '\n')
      //for(int j = 0; j < m; j++) cout << mp[i][j] << ' ';
    
    cout << xa.size() << '\n';
    for(int i = 0; i < (int)xa.size(); i++)
      cout << xa[i] << ' ' << ya[i] << ' '<< da[i] << '\n';
  }
}
