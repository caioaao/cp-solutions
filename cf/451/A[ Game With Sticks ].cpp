#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n,m;
  while(cin >> n >> m){
    if(min(n,m)%2)
      cout << "Akshat\n";
    else
      cout << "Malvika\n";
  }
}
