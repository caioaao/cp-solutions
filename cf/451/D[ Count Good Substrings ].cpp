#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  char c;
  long long a_o = 0, a_e = 0, b_o = 0, b_e = 0, ans_o = 0,ans_e = 0;
  string s;
  getline(cin,s);
  for(int i = 0; i < (int)s.size(); i++){
    c = s[i];
    if(c != &#39;a&#39; && c != &#39;b&#39;) break;
    
    ans_o++;
    //~ cout << b_o << &#39; &#39; << b_e << endl;
    if(c == &#39;a&#39;){
      if(i%2 == 0){
    ans_o += a_e;
    ans_e += a_o;
    a_e++;
      }
      else{
    ans_o += a_o;
    ans_e += a_e;
    a_o++;
      }
    }
    else{
      if(i%2 == 0){
    ans_o += b_e;
    ans_e += b_o;
    b_e++;
      }
      else{
    ans_o += b_o;
    ans_e += b_e;
    b_o++;
      }
    }
  }
  cout << ans_e << &#39; &#39; << ans_o << &#39;\n&#39;;
}
