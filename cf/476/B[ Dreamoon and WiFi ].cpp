#include <bits/stdc++.h>

#define MAXN 200

using namespace std;
typedef double dd;
string S;
int N, final;

dd memo[MAXN][MAXN];
bool mf[MAXN][MAXN];

dd dp(int ps, int po){
  if(!mf[ps][po]){
    mf[ps][po] = 1;
    if(ps == N) memo[ps][po] = po == final;
    else{
      if(S[ps] == &#39;?&#39;) memo[ps][po] = (dp(ps+1, po+1) + dp(ps+1,po-1))/2;
      else             memo[ps][po] = dp(ps+1, po + (S[ps] == &#39;+&#39; ? 1 : -1));
    }
  }
  return memo[ps][po];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  
  while(cin >> S){
    final = 0;
    for(int i = 0; i < (int)S.size(); i++) final += (S[i] == &#39;+&#39; ? 1 : -1);
    
    cin >> S;
    N = S.size();
    memset(mf, 0, sizeof mf);
    cout << dp(0,0) << &#39;\n&#39;;
  }
}
