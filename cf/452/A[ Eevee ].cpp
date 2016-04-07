#include <bits/stdc++.h>

using namespace std;

string names[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(){
  ios_base::sync_with_stdio(false);
  int n; string nam;
  while(cin >> n){
    cin >> nam;
    for(int i = 0; i < 8; i++){
      if(n != names[i].size()) continue;
      
      bool matches = true;
      for(int j = 0; j < n; j++){
	if(nam[j] != &#39;.&#39; && nam[j] != names[i][j]){
	  matches = false;
	  break;
	}
      }
      if(matches){
	cout << names[i] << &#39;\n&#39;;
	break;
      }
    }
  }
}
