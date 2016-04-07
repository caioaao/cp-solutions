#include <bits/stdc++.h>

using namespace std;
typedef long long L;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  L n, lo[3], hi[3];

  cin >> n;

  L minL = 0;

  for(int i = 0; i < 3; ++i)
  {
    cin >> lo[i] >> hi[i];
    minL += lo[i];
  }

  for(int i = 0; i < 3; ++i)
  {
    minL -= lo[i];
    cout << min(hi[i], n - minL) << &#39; &#39;;
    n -= min(hi[i], n - minL);
  }
}