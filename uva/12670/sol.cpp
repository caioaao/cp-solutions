#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[61][2];

ll dp(int id, bool eq, ll &bm){
  //~ cout << id << '\n';
  if(id == -1) return 0;
  if(memo[id][eq] != -1) return memo[id][eq];
  
  if(eq){
    if((bm&(1ll<<id)) != 0){
      //~ cout << id << ':' << dp(id-1, 0, bm) << ' ' << dp(id-1,1,bm) + () << endl;
      memo[id][eq] = dp(id-1, 0, bm) + dp(id-1,1,bm) + (bm&((1ll<<id)-1)) + 1;
    }
    else{
      memo[id][eq] = dp(id-1,1,bm);
    }
  }
  else{
    memo[id][eq] = 2ll*dp(id-1,0,bm) + (1ll<<id);
  }
  return memo[id][eq];
}

ll calc(ll x){
  memset(memo, -1, sizeof memo);
  
  //~ dp(59,1,x);
  //~ for(int i = 0; i < 2; i++){
    //~ for(int j = 30; j >= 0; j--){
      //~ cout << memo[j][i] << ' ';
    //~ }
    //~ cout << '\n';
  //~ }
  
  return dp(60, 1, x);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll a, b;
  while(cin >> a >> b){
    //~ cout << calc(a-1) <<  ' ' << calc(b) << '\n';
    cout << calc(b) - calc(a-1) << '\n';
  }
}
