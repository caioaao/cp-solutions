#include <bits/stdc++.h> 
#define MAXN 3001

using namespace std;

int n, a[MAXN], m, f0;

bool visited[MAXN];
int cyc_id[MAXN], p[MAXN], cyc_len[MAXN];
int c;

void dfs(int u, int cid, int pa, int rt){
  p[u] = pa;
  cyc_len[cid]++;
  visited[u] = 1;
  cyc_id[u] = cid;
  if(u == rt) return;
  dfs(a[u], cid, u, rt);
}

void build_cs(){
  memset(visited, 0, sizeof visited);
  c = 0;
  for(int i = 0; i < n; i++)if(!visited[i]){
    cyc_len[c] = 0;
    dfs(a[i],c++, i, i);
  }
}

int main(){
  while(cin >> n){
    f0 = 0;
    for(int i = 0; i < n; i++){
      cin >> a[i];
      a[i]--;
      visited[i] = 0;
    }
    cin >> m;
    

    build_cs();
    
    cout << abs(n - m - c) << &#39;\n&#39;;
    bool first = 1;
    if(n - m < c){
      memset(visited, 0, sizeof visited);
      visited[0] = 1;
      for(int i = 1; i < n && c > n - m; i++) if(!visited[cyc_id[i]]){
        visited[cyc_id[i]] = 1;
        c--;
        if(!first)cout << &#39; &#39;;
        first = false;
        cout<< 1 << &#39; &#39; << i+1;
      }
    }
    else if(n-m > c){
      while(n-m > c){
        int i = 0;
        for(; i < n; i++){
          if(cyc_len[cyc_id[i]] >= 2) break;
        }
        assert(i < n-1);
        
        for(int j = i+1; j < n; j++){
          if(cyc_id[i] == cyc_id[j]){
            swap(a[i],a[j]);
            
            if(!first)cout << &#39; &#39;;
            first = false;
            cout << i+1 << &#39; &#39; << j+1;
            break;
          }
        }
        build_cs();
      }
    }
    cout << &#39;\n&#39;;
  }
}
