#include <bits/stdc++.h>


using namespace std;

int vals[100], n, memo[100][1<<17], memoc[100][1<<17], bms[70];


int dp(int id, int bm){
  if(id == n) return 0;
  if(memoc[id][bm] != -1) return memoc[id][bm];
  memoc[id][bm] = dp(id+1, bm) + vals[id]-1;
  memo[id][bm] = 1;
  int r;
  for(int i = 2; i < 2*vals[id]; i++) if((bms[i] & bm) == 0){
    r = dp(id+1, bm | bms[i]) + abs(vals[id] - i);
    if(memoc[id][bm] > r){
      memoc[id][bm] = r;
      memo[id][bm] = i;
    }
  }
  return memoc[id][bm];
}

void print(int id, int bm){
  if(id == n) return;
  cout << memo[id][bm] << &#39; &#39;;
  print(id+1, bm | bms[memo[id][bm]]);
}


void calc_bms(){
  vector<bool> is_p(70,true);
  vector<int> ps;
  
  for(int i = 2; i <= 60; i++){
    if(is_p[i]){
      ps.push_back(i);
      for(int j = i+i; j <= 60; j+=i) is_p[j] = false;
    }
  }
  
  bms[0] = 0;
  bms[1] = 0;
  for(int i = 2; i <= 60; i++){
    for(int j = 0; j < (int)ps.size(); j++){
      if(i%ps[j] == 0){
        bms[i] |= (1 << j);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  calc_bms();
  
  while(cin >> n){
    for(int i = 0; i < n; i++){
      cin >> vals[i];
    }
  
    memset(memoc, -1, sizeof memoc);
  
    dp(0,0);
    print(0,0);
  }
}
