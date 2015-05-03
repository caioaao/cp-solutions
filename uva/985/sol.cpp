#include <bits/stdc++.h>

#define MAX_N 505
#define INF 100000
#define ROT(X) ((X) + 1)%4

using namespace std;

int dist[MAX_N][MAX_N][4], dirs[MAX_N][MAX_N][4];


inline int dir_from_c(char c){
  if(c == 'N') return 0;
  if(c == 'E') return 1;
  if(c == 'S') return 2;
               return 3;
}

int dr[4] = {-1, 0, 1, 0},
    dc[4] = { 0, 1, 0, -1};

int n,m;


bool is_valid(int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= m) return false;
  return true;
}

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int bfs(){
  memset(dist, -1, sizeof(dist));
  queue<iii> q;
  dist[0][0][0] = 0;
  q.push(iii(0,ii(0,0)));
  while(!q.empty()){
    iii u = q.front();q.pop();
    if(u.first == n-1 && u.second.first == m-1) return dist[u.first][u.second.first][u.second.second];
    
    for(int i = 0; i < 4; i++){
      if(!dirs[u.first][u.second.first][i]) continue;
      int j = (u.second.second+i)%4;
      int nx = u.first+dr[j], ny = u.second.first + dc[j];
      if(is_valid(nx, ny) && dist[nx][ny][ROT(u.second.second)] == -1){
        dist[nx][ny][ROT(u.second.second)] = dist[u.first][u.second.first][u.second.second]+1;
        q.push(iii(nx,ii(ny,ROT(u.second.second))));
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  string aux;
  while(cin >> n >> m){
    memset(dirs, 0, sizeof dirs);
    getline(cin,aux);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(i == n-1 && j == m-1) break;
        getline(cin,aux);
        for(int k = 0; k < (int)aux.length(); k++) dirs[i][j][dir_from_c(aux[k])] = 1;
      }
    }
    int ans = bfs();
    
    //~ for(int i = 0; i < n; i++,cout << endl)
      //~ for(int j = 0; j < m; j++, cout<< ' ')
        //~ for(int k = 0; k < 4; k++) cout << dist[i][j][k] << ',';
    
    if(ans != -1) cout << ans << '\n';
    else cout << "no path to exit\n";
  }
}
