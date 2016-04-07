#include <bits/stdc++.h>

#define LSOne(x) ((x)&(-(x)))

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi ft;
class FenwickTree{
public:
FenwickTree(int n){ft.assign(n+1,0);}
ll rsq(int b){
  ll sum = 0; for(; b; b -= LSOne(b)) sum += ft[b];
  return sum;
}
void adjust(int k){
  for(; k < (int) ft.size(); k+= LSOne(k)){
    ft[k]++;
    //~ cout << k << endl;
  }
}
};

ll vals[1000001], f1[1000001], fn[1000001], vt[2000002];
map<ll,ll> amt, ids;
int main(){
  ios_base::sync_with_stdio(false);
  
  
  int n;
  while(cin >> n){
    amt.clear();
    for(int i = 0; i < n; i++){
      cin >> vals[i];
      if(!amt.count(vals[i])){
	amt[vals[i]] = 0;
      }
      
      vt[i] = f1[i] = ++amt[vals[i]];
    }
    
    
    amt.clear();
    for(int i = n-1; i >= 0; i--){
      if(!amt.count(vals[i])){
	amt[vals[i]] = 0;
      }
      
      vt[n+i] = fn[i] = ++amt[vals[i]];
    }
    
    sort(vt, vt+2*n);
    ids.clear();
    int id = 1;
    for(int i = 0; i < 2*n; i++){
      if(!ids.count(vt[i])) ids[vt[i]] = id++;
    }
    
    FenwickTree fen(2*n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
      ans = ans + fen.rsq(id) - fen.rsq(ids[fn[i]]);
      fen.adjust(ids[f1[i]]);
    }
    
    cout << ans << &#39;\n&#39;;
  }
}
