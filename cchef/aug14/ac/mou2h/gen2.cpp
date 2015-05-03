#include <bits/stdc++.h>
using namespace std;

int main(){
  cout << 100000 << '\n';
  for(int i = 0; i < 100000; i++){
    cout << 10 << '\n';
    for(int j = 0; j < 10; j++){
      if(j%2){
        cout << 2000000-j << '\n';
      }
      else{
        cout << j - 2000000 << '\n';
      }
    }
  }
}
