#include <bits/stdc++.h>

#define EPS 1e-7
#define MAXN 200010

using namespace std;
typedef long long L;
typedef double D;

L a[MAXN], n, w;

inline bool check (D x)
{
  for(int i = 0; i <   n; ++i) if(x     > a[i]) return false;
  for(int i = n; i < 2*n; ++i) if(x * 2 > a[i]) return false;

  return true;
}

inline D bs()
{
  D lo = 0,
    hi = w,
    mi;

  while((hi - lo) > EPS)
  {
    mi = (lo + hi)/2.;
    if(check(mi / (3. * n))) lo = mi;
    else          hi = mi;
  }

  return lo;
}


int main(){
  ios_base::sync_with_stdio(0);

  cin >> n >> w;

  for(int i = 0; i < 2*n; ++i) cin >> a[i];

  sort(a, a+(2*n));

  cout << fixed << setprecision(12) << bs() << &#39;\n&#39;;

  return 0;
}