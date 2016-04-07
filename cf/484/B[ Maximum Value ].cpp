#include <bits/stdc++.h>

#define MAXN 200100
#define MAXV 2000000

using namespace std;
typedef long long ll;

ll vals[MAXN];

ll m_v[MAXV];

bool seen[MAXV];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> vals[i];
  
  int ptr = 0;
  memset(seen,0,sizeof seen);
  for(int i = 0; i < N; i++) if(!seen[vals[i]]){
    seen[vals[i]] = 1;
    vals[ptr++] = vals[i];
  }
  N = ptr;
  
  
  sort(vals,vals+N);
  ll la = 0;
  for(int i = 0; i < N; i++){
    for(ll k = la; k < vals[i]; k++) m_v[k] = la;
    la = vals[i];
  }
  
  for(ll k = la; k < MAXV; k++) m_v[k] = la;
  
  ll bst = 0;
  for(int i = 0; i < N; i++)
    for(ll j = vals[i]*2; j < MAXV; j+= vals[i]) bst = max(bst, m_v[j-1] % vals[i]);
  cout << bst << &#39;\n&#39;;
}
