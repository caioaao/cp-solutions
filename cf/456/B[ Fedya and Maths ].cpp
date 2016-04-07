#include <bits/stdc++.h>

using namespace std;

int vals[5][4] = {{1,1,1,1},
                  {1,1,1,1},
                  {2,4,8,6},
                  {3,9,7,1},
                  {4,6,4,6}};


int getnum(string &s){
  int ans = 0;
  for(int i = s.size()-1, c = 1; i >= 0 && c <= 10; i--, c*=10){
    ans += (s[i]-&#39;0&#39;)*c;
  }
  //~ cout << ans << endl;
  if(ans == 0) return 100;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  string s;
  while(cin >> s){
    if(s == "0"){
      cout << "4\n";
      continue;
    }
    int alg = getnum(s);
    int cyc = (alg-1)%4;
    int ans = 0;
    for(int i = 1; i <=4; i++){
      ans += vals[i][cyc];
    }
    cout << ans%5 << &#39;\n&#39;;
  }
}
