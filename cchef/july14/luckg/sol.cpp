#include <bits/stdc++.h>

#define MAX_NM 1000001

using namespace std;

vector<vector<int> > nums;
vector<bool> visited, fin;
vector<int> nxt, somas;

int T, n, m, N;

int nx;

int main(){
  ios_base::sync_with_stdio(false);
  
  string msg = "No Solution\n";
  cin >> T;
  while(T--){
    cin >> n >> m;
    
    nums.assign(n, vector<int>());
    visited.assign(n,0);
    nxt.assign(n,0);
    fin.assign(n,0);
    somas.assign(n,0);
    int x = n*m;
    bool ver = false;
    
    for (int i = 0; i < n; i++) { 
      cin >> nxt[i];
      if(i == nxt[i]) ver = true;
    }
    
    int lps;
    if(ver){
      cout << msg;
      goto dead;
    }

    for(int i = 0, u; i < n; i++)if(!visited[i]){
      u = i;
      lps = 0;
      do{
        lps++;
        visited[u] = 1;
        u = nxt[u];
      } while(u != i);
      
      u = i;
      while(lps > 0){
        if((int)nums[u].size() == m){
          u = nxt[u];
          continue;
        }
        nums[u].push_back(x--);
        somas[u] += m - nums[nxt[u]].size();
        if((int)nums[u].size() == m){
          if(somas[u]*2 <= m*m){
            cout << msg;
            goto dead;
          }
          lps--;
        }
        if(nums[u].size() > nums[nxt[u]].size())
          u = nxt[u];
      }
    }
    
    bool fst;
    for(int i = 0; i < n; i++){
      fst = true;
      for(int j = m-1; j >= 0; j--){
        if(!fst) cout << ' ';
        fst = false;
        cout << nums[i][j];
      }
      //~ cout << ':' << somas[i];
      cout << '\n';
    }
    
    dead:
    continue;
  }
}
