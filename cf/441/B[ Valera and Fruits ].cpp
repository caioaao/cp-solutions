#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n, v;
  
  cin >> n >> v;
  
  vii vals(n);
  
  for(int i = 0; i < n; i++){
    cin >> vals[i].first >> vals[i].second;
  }
  
  sort(vals.begin(), vals.end());
  
  int ans = 0, aux, needed, got;
  for(int i = 1; i <= 3001; i++){
    aux = 0;
    for(int j = 0; j < n && vals[j].first <= i+1; j++){
      if((vals[j].first == i || vals[j].first+1 == i) && aux < v){
        needed = v - aux;
        got = min(needed, vals[j].second);
        aux+= got;
        vals[j].second -= got;
      }
    }
    ans += aux;
  }
  
  cout << ans;
}
