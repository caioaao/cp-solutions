#include <bits/stdc++.h>

using  namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vii a, b;
map<ll,ll>ca,cb;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  while(cin >> n >> m){
    a.clear();b.clear();
    ca.clear(); cb.clear();
    ll x, ai = 0, bi = 0;
    for(int i = 0; i < n; i++){
      cin >> x;
      if(!ca.count(x)){
        ca[x] = ai++;a.push_back(ii(x,0));
      }
      a[ca[x]].second++;
    }
    for(int i = 0; i < m; i++){
      cin >> x;
      if(!cb.count(x)){
        cb[x] = bi++;b.push_back(ii(x,0));
      }
      b[cb[x]].second++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<ii>());
    
    int i = 0, j = 0;
    ll ans = 0;
    while(a[i].first < b[j].first){
      if(a[i].second < b[j].second){
        if(i < ai-1){
          a[i+1].second += a[i].second;
          ans += a[i].second * min(a[i+1].first - a[i].first, b[j].first - a[i].first);
          i++;
        }
        else{
          ans += a[i].second * (b[j].first - a[i].first);
          a[i].first = b[j].first;
        }
      }else{
        if(j < bi-1){
          b[j+1].second += b[j].second;
          ans += b[j].second * min(b[j].first - b[j+1].first, b[j].first - a[i].first);
          j++;
        }
        else{
          ans += b[j].second * (b[j].first - a[i].first);
          b[j].first = a[i].first;
        }
      }
    }
    cout << ans << &#39;\n&#39;;
  }
}
