#include <bits/stdc++.h>

using namespace std;

int n;
int board[15], amt, d1, d2;

void bt(int r, int cm, int d1m, int d2m){
  if(r == n){
    ++amt;
    return;
  }
  
  if((board[r] & cm) == (1<<n)-1) return;
  for(int c = 0; c < n; c++){
    d1 = r+c; d2 = r + (n-c-1);
    if((board[r] & (1 << c)) != 0 || (((1<<c) & cm) != 0) || (((1<<d1) & d1m) != 0) || (((1<<d2) & d2m) != 0) )
      continue;
    bt(r+1, (1<<c) | cm, (1<<d1) | d1m, (1<<d2) | d2m);
  }
  
  return ;
}


int main(){
  ios_base::sync_with_stdio(false);
  
  int caso = 1;
  char aux;
  while(cin >> n, n != 0){
    amt = 0;
    memset(board,0,sizeof board);
    
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        cin >> aux;
        if(aux == '*') board[i] |= (1 << j);
      }
    }
    bt(0,0,0,0);
    cout << "Case " << caso++ << ": " << amt << '\n';
  }
}
