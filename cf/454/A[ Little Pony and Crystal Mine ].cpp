#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n){
    for(int i = 0; i < n/2; i++){
      for(int j = 0; j < n; j++){
        if(j >= n/2 - i && j <= n/2+i) cout << &#39;D&#39;;
        else cout << &#39;*&#39;;
      }
      cout << &#39;\n&#39;;
    }
    
    for(int j = 0; j < n; j++){
      cout << &#39;D&#39;;
    }
    cout << &#39;\n&#39;;
    
    for(int i = n/2-1; i >= 0; i--){
      for(int j = 0; j < n; j++){
        if(j >= n/2 - i && j <= n/2+i) cout << &#39;D&#39;;
        else cout << &#39;*&#39;;
      }
      cout << &#39;\n&#39;;
    }
  }
}
