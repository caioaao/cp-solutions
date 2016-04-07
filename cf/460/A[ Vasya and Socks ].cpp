#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  while(cin >> n >> m){
  int d = 1;
  while(true){
    if(n - d + (d/m) == 0){
      cout << d << &#39;\n&#39;;
      break;
    }
    else d++;
  }
}
}
