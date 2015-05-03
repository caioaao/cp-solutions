#include <bits/stdc++.h>

#define MAX_N 101
#define MAX_X 10010
#define INF 1E10

using namespace std;

int n, r, a[MAX_N];

double memo[MAX_N], b, v, e, f, rsq[MAX_X];
bool memoized[MAX_N][MAX_N];

inline void calc_rsq(){
  rsq[0] = 1.0/(v - f*r);
  for(int i = 1; i <= a[n]; i++)
    if(i < r)
      rsq[i] = rsq[i-1] + 1.0/(v - f*(r - i));
    else
      rsq[i] = rsq[i-1] + 1.0/(v - e*(i-r));
}

int main(){
  ios_base::sync_with_stdio(false);
  a[0] = 0;
  while(cin >> n, n!= 0){
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    
    cin >> b >> r >> v >> e >> f; 
    calc_rsq();
    for(int i =0; i < n; i++){
      memo[n] = 0.0;
    }
    
    int dx;
    double aux;
    for(int i = n-1; i >= 0; i--){
      memo[i] = INF; 
      for(int j = i+1; j <= n; j++){
        memo[i] = min(memo[i],memo[j] + rsq[a[j]-a[i]-1] + b);
      }
    }
    
    cout << fixed << setprecision(4) << memo[0] - b << '\n';
  }
}
