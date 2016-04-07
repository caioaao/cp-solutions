#include <bits/stdc++.h>

using namespace std;

int has1[30], has2[30];
int nxt[200][30];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s1, s2;
  int n1, n2;
  while(cin >> s1 >> s2){
    bool aut = false, arr = false, tr = false;
    memset(has1, 0, sizeof has1);
    memset(has2, 0, sizeof has2);
    n1 = s1.size();
    n2 = s2.size();
    for(int i = 0; i < n1; i++)has1[s1[i]-&#39;a&#39;]++;
    for(int i = 0; i < n2; i++)has2[s2[i] - &#39;a&#39;]++;
    for(int i = 0; i < 30; i++)
      if(has1[i] < has2[i]){
        tr = true;
      }
      else if(has1[i] > has2[i]){
        aut = true;
      }
    
    if(tr){
      cout << "need tree\n";
      continue;
    }
    
    for(int i = 0; i < 30; i++) nxt[n1][i] = n1;
    
    for(int i = n1-1; i >= 0; i--){
      for(int j = 0; j < 30; j++){
        nxt[i][j] = nxt[i+1][j];
      }
      nxt[i][s1[i]-&#39;a&#39;] = i;
    }
    
    for(int i = 0, j = -1; i < n2; i++){
      if(nxt[j+1][s2[i]-&#39;a&#39;] == n1){
        arr = true;
        break;
      }
      j = nxt[j+1][s2[i]-&#39;a&#39;];
    }
    
    if(arr && aut){
      cout << "both\n";
    }
    else if(arr){
      cout << "array\n";
    }
    else if(aut){
      cout << "automaton\n";
    }
  }
}
