#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  long long n,m,q,lb, hb;
  cin >> n >> m;
  while(m--){
    cin >> q;
    //~ if(q < n+2) cout << "0\n";
    //~ else{
      if(q - 1 <= 2*n){
        lb = 1;
      }
      else{
        lb = q - 2*n;
      }
      if(q -n >= n+1){
        hb = n;
      }
      else{
        hb = q - (n + 1);
      }
      //~ cout << q<< ':' << lb << ',' << hb << endl;
      cout << max(0ll,hb - lb + 1)<< '\n';
    //~ }
  }
}
