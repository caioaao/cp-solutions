#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int vals[100001];

int main(){
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  int amt = 0, las;
  cin >> vals[0];
  
  for(int i = 1; i < n; i++){
    cin >> vals[i];
    
    if(vals[i] < vals[i-1]){
      amt++;
      las = i-1;
    }
  }
  
  if(amt == 0){
    cout << "0\n";
  }
  else if(amt > 1){
    cout << "-1\n";
  }
  else{
    if(vals[0] < vals[n-1]){
      cout << "-1\n";
    }
    else{
      cout << n-las-1 << &#39;\n&#39;;
    }
  }
}
