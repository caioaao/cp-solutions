#include <bits/stdc++.h>

#define MAX_N 1002
#define MAX_L 1002
#define MAX_K 1002

using namespace std;

typedef long long ll;

struct line{
  ll m,b;
  line(){}
  line(ll m_, ll b_):m(m_), b(b_){ }
  ll eval(ll x){
    return m*x + b;
  }
};

// testa se line 2 eh irrelevante
bool irrelevant(line l1, line l2, line l3){
  return (l1.b - l3.b)/(double)(l3.m - l1.m) < (l1.b - l2.b)/(double)(l2.m - l1.m);
}


line lines[MAX_L];
int hbl; // ultimo elemento de lines: inicializar com 0

void add_line(ll m, ll b){
  line curr(m,b);
  
  while(hbl >= 2 && irrelevant(lines[hbl-2],lines[hbl-1], curr)){
    hbl--;
  }
  lines[hbl++] = curr;
}

int pointer;
ll query(ll x){
  if(pointer >= hbl)
    pointer = hbl-1;

  while(pointer < hbl-1 && lines[pointer+1].eval(x) < lines[pointer].eval(x) )
    pointer++;

  return lines[pointer].eval(x);
}

void beg_cvt(){
  hbl = pointer = 0;
}

ll vals[MAX_N], xs[MAX_N], S[MAX_N], G[MAX_N], dp[MAX_N][2];

int main(){
  ios_base::sync_with_stdio(false);
  
  ll n, K;
  int r = 0;
  while(cin >> n >> K){
    for(int i = 0; i < n; ++i){
      cin >> xs[i] >> vals[i];
    }
    
    S[0] = vals[0];
    G[0] = vals[0]*xs[0];
    
    for(int i = 1; i < n; i++){
      S[i] = S[i-1] + vals[i];
      G[i] = G[i-1] + vals[i]*xs[i];
    }
    dp[n-1][r] = 0;
    for(int i = n-2; i >= 0; i--){
      dp[i][r] = dp[i+1][r] + vals[i]*(xs[n-1]-xs[i]);
    }
    r^= 1;
    for(int k = 2; k <= K; k++, r^=1){
      dp[n-k][r] = 0;
      beg_cvt();
      add_line(xs[n-k], dp[n-k+1][r^1] + xs[n-k]*S[n-k] - G[n-k]);
      for(int i = n-k-1; i >=0; i--){
        add_line(xs[i], dp[i+1][r^1] + xs[i]*S[i] - G[i]);
        dp[i][r] = query(i > 0 ? - S[i-1]:0) + (i > 0 ? G[i-1] : 0);
      }
    }
    cout << dp[0][r^1] << '\n';
  }
}
