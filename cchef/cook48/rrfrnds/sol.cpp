#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll AdjMat[2001][35], n;
bool AdjMatN[2001][2001];

void printbm(ll bm){
  for(int i = 63; i >= 0; i--){
    cout << ((bm&(1ll<<i))!=0);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  
  memset(AdjMat, 0, sizeof AdjMat);
  memset(AdjMatN, 0, sizeof AdjMatN);
  
  char c;
  int ans = 0;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> c;
      if(c == '1'){
        AdjMat[i][j/63] |= (1ll << (j%63));
        AdjMatN[i][j] = 1;
        
      }
    }
    for(int j = 0; j < i; j++){
      if(AdjMatN[i][j] || AdjMatN[j][i]) continue;
      
      for(int k = 0; k <= n/63; k++){
        if((AdjMat[i][k] & AdjMat[j][k]) != 0){
          ans+=2;break;
        }
      }
    }
  }
  cout << ans << '\n';
}
