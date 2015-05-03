#include <bits/stdc++.h>

using namespace std;

vector<int> nxt, visited;
vector<vector<int> > nums;

int main(){
  ios_base::sync_with_stdio(false);
  int t, n, m, lps, u, amt;
  cin >> t;
  
  while(t--){
    cin >> n >> m;
  
    nxt.assign(n,0);
    nums.assign(n,vector<int>());
  
    bool faio = false;
  
    int l = n*m;
  
    for(int i = 0; i < n; i++)
      cin >> nxt[i];
  
    if(m <= 2){
      faio = true;
      goto fim;
    }
    
    visited.assign(n,0);
    
    for(int i = 0; i < n; i++) if(!visited[i]){
      u = i;
    
      amt = 1;
      lps = 0;
    
      do{
        visited[u] = true;
        lps++;
        for(int j = 0; j < amt; j++){
          nums[u].push_back(l--);
        }
        if(amt < m) amt++;
        u = nxt[u];
      }while(u != i);
      
      if(lps <= 2){
        faio = true;
        goto fim;
      }
      
      u = i;
      do{
        while((int)nums[u].size() < m)
          nums[u].push_back(l--);
        u = nxt[u];
      }while(u != i);
    }
    
    fim:
    if(faio){
      cout << "No Solution\n";
    }
    else{
      for(int i = 0; i < n; i++){
        bool fst = true;
        for(int j = m-1; j >= 0; j--){
          if(!fst) cout << ' ';
          fst = false;
          cout << nums[i][j];
        }
        cout << '\n';
      }
    }
  }
}
