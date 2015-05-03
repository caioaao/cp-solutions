#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


map<string,int> osTypes;
vector<int> cl,cr,osl,osr;

vector<vii> memo;
int n, m;
ii dp(int i, int j){
  if(i == n || j == m) return ii(0,0);
  if(memo[i][j].first > -1) return memo[i][j];
  
  memo[i][j] = max(dp(i,j+1), dp(i+1,j));
  if(osl[i] == osr[j]){
    ii aux = dp(i+1,j+1);
    aux.first += cl[i]+cr[j];
    aux.second--;
    memo[i][j] = max(memo[i][j],aux);
  }
  
  return memo[i][j];
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int t, aux;
  cin >> t;
  string c, os;
  while(t--){
    int ostype = 0;
    osTypes.clear();
    
    cin >> n;
    osl.assign(n,0);
    cl.assign(n,0);
    for (int i = 0; i < n; i++){
      cin >> c >> os >> aux;
      if(!osTypes.count(os))
        osTypes[os] = ostype++;
        
      osl[i] = osTypes[os];
      cl[i] = aux;
    }
    
    cin >> m;
    osr.assign(m,0);
    cr.assign(m,0);
    for (int i = 0; i < m; i++){
      cin >> c >> os >> aux;
      
      if(!osTypes.count(os))
        osTypes[os] = ostype++;
        
      osr[i] = osTypes[os];
      cr[i] = aux;
    }
    
    memo.assign(n,vii(m,ii(-1,-1)));
    ii ans = dp(0,0);
    cout << ans.first << ' ' << -ans.second << '\n';
  }
}  
