#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[100000];

int main(){
  ios_base::sync_with_stdio(false);
  
  ll n,m,r,x, aux;
  char c;
  while( cin >> n >> m){
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    r = 0;
    
    while(m--){
      cin >> c >> x;
      if(c == 'A') r -= x;
      else if(c == 'C') r += x;
      else{
        aux = x + r - 1;
        if(abs(aux) >= n) aux %= n;
        if(aux < 0) aux += n;
        cout << arr[aux] << '\n';
      }
      
      if(abs(r) >= n) r %= n;
    }
  }
}
