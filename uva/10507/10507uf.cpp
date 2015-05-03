#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int n;

map<char, int> cToV;
vi p;
int amtS;
void UF(){p.assign(n,0); for(int i = 0; i < n; i++) p[i] = i; amtS = n;}
int findSet(int u){return p[u] = u == p[u] ? p[u] : findSet(p[u]); }
bool isSameSet(int u, int v){ return findSet(u) == findSet(v);}
void unionSet(int u, int v){
  if(!isSameSet(u,v)){
    amtS--;
    p[findSet(u)] = findSet(v);
  }
}

vector<vi> AdjList;
vi awaken;

int main(){
  ios_base::sync_with_stdio(false);
  
  int m;
  char c, c_a, c_b;
  while(cin >> n){
    cin >> m;
    
    cToV.clear();
    int n_u = 0;
    AdjList.assign(n,vi());
    awaken.assign(n,0);
    
    for(int i = 0; i < 3; i++){
      cin >> c;
      cToV[c] = n_u;
      awaken[n_u++] = 1;
    }
    
    UF();
    unionSet(0,1);
    unionSet(1,2);
    
    int u1, u2;
    for(int i = 0; i < m; i++){
      cin >> c_a >> c_b;
      if(!cToV.count(c_a)){
        cToV[c_a] = n_u++;
      }
      u1 = cToV[c_a];
      
      if(!cToV.count(c_b)){
        cToV[c_b] = n_u++;
      }
      u2 = cToV[c_b];
      
      AdjList[u1].push_back(u2);
      AdjList[u2].push_back(u1);
    }
    
    int y = 0;
    bool changed = true;
    while(changed && amtS > 1){
      changed = false;
      vi toBeAdded;
      for(int i = 0; i < n; i++){
        if(awaken[i])continue;
        int amt = 0;
        for(int j = 0; j < (int)AdjList[i].size(); j++){
          if(awaken[AdjList[i][j]]) amt++;
        }
        if(amt >= 3) toBeAdded.push_back(i);
      }
      for(int i = 0; i < (int)toBeAdded.size(); i++){
        changed = true;
        awaken[toBeAdded[i]] = 1;
        unionSet(toBeAdded[i],0);
      }
      if(changed) y++;
    }
    
    if(amtS > 1){
      cout << "THIS BRAIN NEVER WAKES UP\n";
    }
    else{
      cout << "WAKE UP IN, " << y << ", YEARS\n";
    }
  }
}
