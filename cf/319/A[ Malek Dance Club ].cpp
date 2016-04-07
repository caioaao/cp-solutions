#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

ll po2[101];
void prec(){
  po2[0] = 1;
  
  for(int i = 1; i < 101; i++)
    po2[i] = (po2[i-1]*2)%MOD;
}

int main(){
  string s;
  prec();
  while(cin >> s){
    ll ons = 0, n = s.size();
    
    for(int i = 0; i < n; i++)
      if(s[i] == &#39;1&#39;) ons = (ons + po2[n-i-1])%MOD;
    
    //~ cout << s << &#39;:&#39; << ons << endl;
    ll ans = 1;
    
    for(int i = 0; i < n-1; i++){
      ans = (ans * 2)%MOD;
    }
    cout << (ans*ons)%MOD << &#39;\n&#39;;
  }
}
