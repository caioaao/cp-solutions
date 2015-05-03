#include <bits/stdc++.h>

using namespace std;

inline string move_l(int b, int targ, string vi){
  string v = vi;
  if(b < targ)
    for(int i = b; i < targ-1; i++) swap(v[i],v[i+1]);
  else
    for(int i = b; i > targ; i--) swap(v[i],v[i-1]);
  return v;
}
inline string move_r(int b, int targ, string vi){
  string v = vi;
  if(b < targ)
    for(int i = b; i < targ; i++) swap(v[i],v[i+1]);
  else
    for(int i = b; i > targ+1; i--) swap(v[i],v[i-1]);
  return v;
}

string ordered;

map<string,int> dist;
bool sex[9];
inline bool prime(int x){ return x == 1 || x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13; }

int bfs(string init){
  dist.clear();
  queue<string> q;
  dist[init] = 0;
  string u,v;
  q.push(init);
  while(!q.empty()){
    u = q.front(); q.pop();
    if(ordered == u) return dist[u];
    
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(i != j && sex[(int)u[i]] != sex[(int)u[j]] && prime(u[i] + u[j])){
          v = move_l(i,j, u);
          if(!dist.count(v)){
            dist[v] = dist[u]+1;
            q.push(v);
          }
          v = move_r(i,j, u);
          if(!dist.count(v)){
            dist[v] = dist[u]+1;
            q.push(v);
          }
        }
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  int aux;
  string str(8, '\0');
  ordered = string(8,'\0');
  for(int i = 0; i < 8; i++) ordered[i] = i+1;
  int caso = 1;
  while(cin >> aux, aux != 0){
    str[0] = abs(aux);
    sex[abs(aux)] = aux > 0;
    
    for(int i = 1; i < 8; i++){
      cin >> aux;
      str[i] = abs(aux);
      sex[abs(aux)] = aux > 0;
    }
    
    cout << "Case " << caso++ << ": " << bfs(str) << '\n';
  }
}
