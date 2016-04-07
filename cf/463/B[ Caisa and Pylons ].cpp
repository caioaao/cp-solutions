#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  ll inc = 0, e = 0, la = 0, curr;
  for(int i = 0; i < n; i++){
    cin >> curr;
    e += la - curr;
    la = curr;
    if(e < 0){
      inc -= e;
      e = 0;
    }
  }
  cout << inc << &#39;\n&#39;;
}
