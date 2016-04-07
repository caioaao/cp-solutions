#include <bits/stdc++.h>

#define MAXN 500005

using namespace std;
typedef long long ll;


int val[MAXN], cnt[MAXN+1];

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n){
    memset(cnt,0,sizeof cnt);
    ll tot = 0;
    for(int i = 0; i < n; i++){
      cin >> val[i];
      tot += val[i];
    }
    if(tot % 3){
      cout << "0\n";
      continue;
    }
    tot /= 3;
    ll s = 0;
    for(int i = n-1; i >= 0; i--){
      s += val[i];
      cnt[i] = cnt[i+1];
      if(s == tot) cnt[i]++;
    }
    ll ans = 0;
    s = 0;
    for(int i = 0; i < n; i++){
      s += val[i];
      if(s == tot){ans += cnt[i+2];}
    }
    cout << ans << &#39;\n&#39;;
  }
}
