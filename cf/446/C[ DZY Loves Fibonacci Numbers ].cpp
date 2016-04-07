#include <bits/stdc++.h>

#define MAX_N 300010
#define MOD 1000000009
#define CL(x) 2*(x)
#define CR(x) 2*(x) + 1

using namespace std;
typedef long long ll;
ll fib[MAX_N], fs[MAX_N][2], fm[MAX_N][2], A[MAX_N], st[20*MAX_N], lazy_a[20*MAX_N], lazy_b[20*MAX_N];

int n, m;

void build(int node, int L, int R){
  lazy_a[node] = lazy_b[node] = 0;

  if(L == R){
    st[node] = A[L];
    return;
  }
  
  build(CL(node), L, (L+R)/2);
  build(CR(node), (L+R)/2 + 1, R);
  
  st[node] = (st[CL(node)] + st[CR(node)])%MOD;
}

void relax(int node, int L, int R){
  if(lazy_a[node] == 0) return ;
  
  if(L != R){
    // OK
    lazy_a[CL(node)] = (lazy_a[CL(node)] + lazy_a[node])%MOD;
    lazy_b[CL(node)] = (lazy_b[CL(node)] + lazy_b[node])%MOD;

    // WRONG
    lazy_a[CR(node)] = (lazy_a[CR(node)] + ((fm[(R-L)/2 + 1][0]*lazy_b[node])%MOD + (fm[(R-L)/2 + 1][1]*lazy_a[node])%MOD)%MOD)%MOD;
    lazy_b[CR(node)] = (lazy_b[CR(node)] + ((fm[(R-L)/2 + 2][0]*lazy_b[node])%MOD + (fm[(R-L)/2 + 2][1]*lazy_a[node])%MOD)%MOD)%MOD;
  }
  
  st[node] = (st[node] + ((fs[R-L][0]*lazy_b[node])%MOD + (fs[R-L][1]*lazy_a[node])%MOD)%MOD)%MOD;
  
  lazy_a[node] = lazy_b[node] = 0;
}

ll query(int node, int qL, int qR, int L, int R){
  relax(node, L, R);
  if(R < qL || L > qR) return 0;
  
  if(L >= qL &&  R <= qR){
    return st[node];
  }
  
  return (query(CL(node), qL, qR, L, (L+R)/2) + query(CR(node), qL, qR, (L+R)/2 + 1, R))%MOD;
}

void update(int node, int qL, int qR, int L, int R){
  relax(node, L, R);
  if(R < qL || L > qR) return;
  if(L == R){
    st[node] = (st[node] + fib[L-qL])%MOD;
    
    return ;
  }
  if(L >= qL && R <= qR){
    lazy_a[node] = fib[L-qL];
    lazy_b[node] = fib[L-qL+1];
    
    relax(node, L, R);
    
    return ;
  }
  
  update(CL(node), qL, qR, L, (L+R)/2);
  update(CR(node), qL, qR, (L+R)/2 + 1, R);
  st[node] = (st[CL(node)] + st[CR(node)])%MOD;
}
typedef vector<ll> vll;
typedef vector<vll> vvll;
vvll M(2, vll(2,1));
inline void mmult(const vvll &A, vvll &B){
  B.assign(2, vll(2,0));
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < 2; k++){
        B[i][j] = (B[i][j] + (A[i][k]*M[k][j])%MOD)%MOD;
      }
    }
  }
}

void precalc(){
  fib[0] = fib[1] = 1;
  for(int i = 2; i < MAX_N; i++) fib[i] = (fib[i-1] + fib[i-2])%MOD;
  
  M[1][1] = 0;
  
  vvll A(2, vll(2,0)), m_n;
  A[0][0] = A[1][1] = 1;
  fs[0][0] = fm[0][0] = 0;
  fs[0][1] = fm[0][1] = 1;
  for(int i = 1; i < MAX_N; i++){
    mmult(A, m_n);
    A = m_n;
    
    fm[i][0] = A[1][0];
    fm[i][1] = A[1][1];
    
    fs[i][0] = fs[i-1][0] + A[1][0];
    if(fs[i][0] > MOD) fs[i][0] %= MOD;
    
    fs[i][1] = fs[i-1][1] + A[1][1];
    if(fs[i][1] > MOD) fs[i][1] %= MOD;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  precalc();
  while(cin >> n >> m){
    for(int i = 0; i < n; i++) cin >> A[i];
    
    build(1, 0, n-1);
    int t,l,r;
    for(int i = 0; i < m; i++){
      cin >> t >> l >> r;
      if(t == 1){
        update(1, l-1, r-1, 0, n-1);
      }
      else if(t == 2){
        ll ans = query(1, l-1, r-1, 0, n-1);
        if(ans < 0) ans += MOD;
        cout << ans << &#39;\n&#39;;
      }
    }
  }
}
