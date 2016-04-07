#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int bs[200000];
void prec(){
  bs[1] = 0;
  int p = 1;
  for(int i = 2; i < 200000; i++){
    if(i < (1 << p))bs[i] = p-1;
    else bs[i] = p++;
  }
}
inline int left(int x){
  return x + bs[x] + ((1 << bs[x]) != x);
  
}

vector<vi> qs;
vi L, R, X;

inline int right(int x){
  if((1 << bs[x]) == x) return left(x)+1;
  return left(x);
}

set<int> ans;


int main(){
  ios_base::sync_with_stdio(false);
  int n,m, typ, lv, l, r, x, q;
  prec();
  while(cin >> n >> m){
    qs.assign(n+1, vi());
    L.clear();
    R.clear();
    X.clear();
    
    for(int i = 0; i < m; i++){
      cin >> typ;
      if(typ == 1){
        cin >> lv >> l >> r >> x;
        qs[lv].push_back(L.size());
        L.push_back(l);
        R.push_back(r);
        X.push_back(x);
      }
      else{
        cin >> lv >> x;
        l = r = x;
        ans.clear();
        for(int i = lv; i <= n; i++){
          for(int j = 0; j < (int)qs[i].size(); j++){
            q = qs[i][j];
            if(!(R[q] < l || L[q] > r))
              ans.insert(X[q]);
          }
          //~ cout << i << &#39;:&#39; << l << &#39;,&#39; << r << &#39;\n&#39;;
          l = left(l);
          r = right(r);
        }
        cout << ans.size() << &#39;\n&#39;;
      }
    }
  }
}
