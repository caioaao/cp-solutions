#include <bits/stdc++.h>

using namespace std;
int n, p;
string ori, ans;

bool memo[1001][27][27][2];

bool dp(int id, int c1, int c2, bool ok){
  if(id == n) return ok;
  if(memo[id][c1][c2][ok]) return 0;
  memo[id][c1][c2][ok] = 1;
  int c;
  if(!ok){
    c = ori[id]-&#39;a&#39;;
    if(c != c1 && c != c2 && dp(id+1, c2, c, 0)){
      ans[id] = ori[id];
      return true;
    }
    c++;
  }
  else{
    c = 0;
  }
  
  for(; c < p; c++) if(c != c1 && c != c2 && dp(id+1, c2, c, 1)){
    ans[id] = c + &#39;a&#39;;
    return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n >> p;
  cin >> ori;
  ans.assign(n,&#39;\n&#39;);
  memset(memo, 0, sizeof memo);
  
  if(dp(0,26,26,0)) cout << ans << &#39;\n&#39;;
  else cout << "NO\n";
}
