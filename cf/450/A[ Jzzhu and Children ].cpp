#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n, m;
  vector<int> vals;
  while(cin >> n >> m){
    vals.assign(n,0);
    for(int i = 0; i < n; i++) cin >> vals[i];
    int last, amt = n;
    while(amt > 0){
      for(int i = 0; i < n; i++){
        //~ cout << vals[i] << &#39; &#39;;
        if(vals[i] > 0){
          vals[i]-=m;
          if(vals[i] <= 0){
            last = i;
            amt--;
          }
        }
      }
      //~ cout << endl;
    }
    cout << last+1 << &#39;\n&#39;;
  }
}
