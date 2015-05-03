#include <iostream>

using namespace std;

int main(){
  cout << "10\n";
  for(int i = 0; i < 10; i++){
    cout << "10000 15000\n";
    for(int i = 0; i < 10000; i++) cout << 1000000000ll << ' ';
    cout << '\n';
    for(int i = 0; i < 15000; i++) cout << 1000000000000000000ll << ' ';
    cout << '\n';
  }
}
