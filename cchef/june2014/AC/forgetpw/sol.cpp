#include <bits/stdc++.h>

using namespace std;

map<char,char> mapa;

int main(){
  ios_base::sync_with_stdio(false);
  
  int t, n;
  char auxK, auxV;
  string s;
  cin >> t;
  while(t--){
    cin >> n;
    mapa.clear();
    for(int i = 0; i < n; i++){
      cin >> auxK >> auxV;
      mapa[auxK] = auxV;
    }
    
    getline(cin, s); // clear
    getline(cin, s);
    //~ cout << s << endl;
    
    bool hasDot = false;
    
    for(int i = 0; i < (int)s.length(); i++){
      if(mapa.count(s[i]))
        s[i] = mapa[s[i]];

      if(s[i] == '.') hasDot = true;
    }
    
    int i;
    for(i = 0; i < (int)s.length() && s[i] == '0'; i++){
      s[i] = '\0';
    }
    
    if(hasDot){
      for(i = (int)s.length()-1; i >= 0  && s[i] == '0'; i--) s[i] = '\0';
      if(i >= 0 && s[i] == '.') s[i] = '\0';
    }
    bool hasD = false;
    for(int i = 0; i < (int)s.length(); i++)
      if(s[i] != '\0' && s[i] != '0' && s[i] != '.'){
        hasD=true;
        break;
      }
    if(hasD){
      //~ cout << s << '\n';
      for(int i = 0; i < (int)s.length(); i++)if(s[i] != '\0') cout << s[i];
      cout << '\n';
      
    }
    else
      cout << "0\n";
  }
}
