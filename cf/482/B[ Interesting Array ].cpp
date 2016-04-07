#include <bits/stdc++.h>


#define MAXN 100010

using namespace std;
typedef long long L;
typedef double D;

int st[4*MAXN], lazy[4*MAXN];

#define cl(x) ((x)<<1)
#define cr(x) (((x)<<1)+1)


void relax(int x, int l, int r){
  st[x] |= lazy[x];
  
  if(l < r){
    lazy[cl(x)] |= lazy[x];
    lazy[cr(x)] |= lazy[x];
  }
  
  lazy[x] = 0;
}

int range_update(int x, int l, int r, int i, int j, int bm){
  relax(x,l,r);
  
  if(i > r || j < l) return st[x];
  
  //cout << x << &#39; &#39; << l << &#39; &#39;<< r << &#39;\n&#39;;
  if(l >= i && r <= j){
    lazy[x] = bm;
    relax(x,l,r);
    return st[x];
  }
  else{
    st[x] = range_update(cl(x), l, (l+r)/2, i, j, bm) &
            range_update(cr(x), (l+r)/2+1, r, i, j, bm);
  }
  return st[x];
}

int query(int x, int l, int r, int i, int j){
  relax(x,l,r);
  
  if(i > r || j < l) return (1<<30)-1;
  if(l >= i && r <= j) return st[x];
  
  return query(cl(x),l, (l+r)/2, i, j) & 
         query(cr(x), (l+r)/2+1, r, i, j);
}

struct qry{
  int a, b, v;
};

qry qs[MAXN];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  
  cin >> n >> m;
  
  memset(st, 0, sizeof st); memset(lazy, 0, sizeof lazy);
  
  for(int i = 0; i < m; i++){ 
    cin >> qs[i].a >> qs[i].b >> qs[i].v;
    //cout << qs[i].a << &#39; &#39; << qs[i].b << &#39; &#39; << qs[i].v << &#39; &#39;;
    
    range_update(1,1,n,qs[i].a, qs[i].b, qs[i].v);
  }
  
  int i = 0; 
  for(; i < m; i++)
    if(query(1,1,n,qs[i].a,qs[i].b) != qs[i].v){
      //cout << query(1,1,n,qs[i].a,qs[i].b) << &#39;\n&#39;;
       break;
     }
    
  if(i < m){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
      cout << query(1,1,n,i,i) << &#39; &#39;;
    }
    cout << &#39;\n&#39;;
  }
}
