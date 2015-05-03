#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
string A,B;
int a, b, n, m, k;
map<ii, int> memo;
#define cmp(x,y) (x == -1 ? y : (y == -1 ? x : (x < y ? x : y)))
int dp(ii state){
  //cout << state[0] << ' ' << state[1] << ' ' << state[2] << '\n';
  
  if(abs(state.first - state.second) > k) return -1;
  
  if(state.first == n && state.second == m) return 0;
  
  if(memo.count(state)) return memo[state];
  
  memo[state] = -1;
  
  int & ans = memo[state];
  
  int aux;
  
  ii s2(0,0);
  
  if(state.first < n){
    s2.first = state.first+1;
    s2.second = state.second;
    aux = dp(s2);
    if(aux != -1)
      ans = cmp(ans,aux + a);
  }
  if(state.second < m){
    s2.first = state.first;
    s2.second = state.second + 1;
    aux = dp(s2);
    if(aux != -1)
      ans = cmp(ans,aux + a);
  }
  if(state.first < n && state.second < m){
    s2.first = state.first + 1;
    s2.second = state.second + 1;
    
    aux = dp(s2);
    
    if(aux != -1)
      ans = cmp(ans,aux + (A[state.first] == B[state.second] ? 0 : b));
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    cin >> A >> B;
    cin >> a >> b >> k;
    if(a == 0 || b == 0){
      cout << "0\n";
      continue;
    }
    n = A.size(); m = B.size();
    
    //cout << n << ' ' << m << '\n';
    //continue;
    
    b = min(b,a*2);
    
    memo.clear();
    int aux = dp(ii(0,0));
    cout << (aux <= k ? aux : -1) << '\n';
  }
}
