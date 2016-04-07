#include <iostream>
#include <set>

using namespace std;
set<char> letras;
int main(){
  ios_base::sync_with_stdio(false);
  char c = &#39;\0&#39;;
  while(cin >> c, c != &#39;}&#39;){
    if(c >= &#39;a&#39; && c <= &#39;z&#39;)
      letras.insert(c);
  }
  cout << letras.size() << &#39;\n&#39;;
}
