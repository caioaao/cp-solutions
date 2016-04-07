#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  string s;
  while(getline(cin, s)){
    int lastI = 0;
    bool ok = true;
    for(int i = 0; i < (int)s.size(); i++){
      if(s[i] == &#39;1&#39;){
        lastI = 1;
      }
      else if(s[i] == &#39;4&#39;){
        if(lastI){
          lastI = (lastI+1)%3;
        }
        else{
          ok = false;
          break;
        }
      }
      else{
        ok = false;
        break;
      }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
  }
}
