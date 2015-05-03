#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);

  ll t, amt[3], m, ma[3], x;
  cin >> t;
  while(t--){
    for(int i = 0; i < 3;i++) cin >> amt[i];
    cin >> m;
    for(int i = 0; i < 3; i++){
      ma[i] = 0;
      for(int j = 0; j < amt[i]; j++){
        cin >> x;
        ma[i] = max(ma[i], x);
      }
    }
    sort(ma,ma+3);
    while(m--){
      ma[2] /=2;
      sort(ma,ma+3);
    }
    cout << ma[2] << '\n';
  }
}
