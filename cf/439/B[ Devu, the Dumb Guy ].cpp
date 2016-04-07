#include <iostream>
#include <algorithm>

#define MAX_N 100010

using namespace std;
typedef long long ll;

ll chaps[MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  ll n,x;
  while(cin >> n >> x){
    for(int i = 0; i < n; i++){
      cin >> chaps[i];
    }
    sort(chaps,chaps+n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
      ans += chaps[i]*x;
      x = max(1ll,x-1);
    }
    cout << ans << &#39;\n&#39;;
  }
}
