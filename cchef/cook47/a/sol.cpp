#include <iostream>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  
  int t; ll n;
  cin >> t;
  while(t--){
    cin >> n;
    
    ll p1, p3, p4;
    if(n < 2) p1 = 0;
    else{
      p1 = n*(n-1)*(n-1);
    }
    if(n < 3) p3 = p4 = 0;
    else{
      p3 = n*(n-1)*(n-2);
      p4 = n*(n-1)*(n-2)*(n-2);
    }
    
    cout << 2*p1+p3+2*p4 << '\n';
  }
}
