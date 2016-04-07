#include <bits/stdc++.h>

#define cl(x) (x)*2
#define cr(x) (x)*2 + 1
#define MAX_N 5001

using namespace std;
typedef long long ll;
typedef set<int, greater<int> > si;
typedef si::const_iterator sit;

int n;

vector<int> vals, lasts;
int st[20*MAX_N];

void build(int u, int l, int r){
  if(l == r) st[u] = l;
  else{
    build(cl(u), l, (l+r)/2);
    build(cr(u), (l+r)/2+1, r);
    st[u] = st[(vals[st[cl(u)]] < vals[st[cr(u)]] ? cl(u) : cr(u))];
  }
}

int rmq(int u, int l, int r, int ql, int qr){
  if(qr < l || ql > r) return -1;
  if(l >= ql && r <= qr) return st[u];
  
  int a = rmq(cl(u), l, (l+r)/2, ql, qr),
      b = rmq(cr(u), (l+r)/2+1, r, ql, qr);
  if(a == -1) return b;
  if(b == -1) return a;
  return (vals[a] < vals[b] ? a : b);
}

int rmq(int ql, int qr){return rmq(1,0,n-1,ql,qr); }

int bt(int l, int r, int l_h){
  if(r < l) return 0;
  int m = rmq(l,r);
  //~ cout << l << &#39;-&#39; << m << &#39;-&#39; << r<< endl;
  return min(r-l+1, bt(l,m-1,vals[m]) + bt(m+1,r,vals[m]) + vals[m] - l_h);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(cin >> n){
    vals.assign(n,0);
    for(int i = 0; i < n; i++){
      cin >> vals[i];
    }
    
    build(1, 0, n-1);
    cout << bt(0,n-1,0) << &#39;\n&#39;;
  }
}
