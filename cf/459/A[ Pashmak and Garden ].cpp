#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int x1, y1, x2, y2;
  
  while(cin >> x1 >> y1 >> x2 >> y2){
    if(x1 == x2){ // iguais na vertical
      cout << x1 + abs(y2-y1) << &#39; &#39;  << y1 << &#39; &#39; << x1 + abs(y2-y1)  << &#39; &#39;  << y2 << &#39;\n&#39;;
    }
    else if(y1 == y2){
      cout << x1 << &#39; &#39; << y1 - abs(x2-x1) << &#39; &#39; << x2 << &#39; &#39; << y1 - abs(x2-x1) << &#39;\n&#39;;
    }
    else if(abs(x1-x2) == abs(y1-y2)){
      cout << x1 << &#39; &#39; << y2 << &#39; &#39; << x2 << &#39; &#39; << y1 << &#39;\n&#39;;
    }
    else{
      cout << "-1\n";
    }
  }
  
}
