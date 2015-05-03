#include <bits/stdc++.h>

using namespace std;

int pot[4] = {10, 100, 1000, 10000};

int main(){
  int n = 800000, m = 200000;
  
  cout << n << '\n';
  
  for(int i = 0; i < n; i++){
    cout << rand()%10000 << ' ';
  }
  cout << '\n';
  
  int typ,l, r;
  
  cout << m << '\n';
  
  for(int i = 0; i < m; i++){
    typ = rand()%2;
    l = rand()%n;
    r = rand()%n;
    if(l > r) swap(l,r);
    cout << typ <<  ' ' << l << ' ' << r;
    if(typ == 1) cout << ' ' << rand()%61;
    cout << '\n';
  }
}
