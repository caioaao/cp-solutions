#include <bits/stdc++.h>

using namespace std;

vector<int> vals;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n;
  while(cin >> n){
    vals.assign(n,0);
    for(int i = 0; i < n; i++){
      cin >> vals[i];
    }
    
    int i = 0, j = n-1, s[2] = {0,0};
    bool turn = false;
    while(i <= j){
      if(vals[i] > vals[j]){
        s[turn] += vals[i];
        i++;
      }
      else{
        s[turn] += vals[j];
        j--;
      }
      
      turn = !turn;
    }
    
    cout << s[0] << &#39; &#39; << s[1] << &#39;\n&#39;;
  }
}
