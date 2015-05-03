#include <iostream>

using namespace std;

int main(){
  long long tot = 1, x;
  while(cin >> x){
    if(1000000000l/x < tot) break;
    tot *= x;
    cout << x << ' ' << tot << endl;
  }
}
