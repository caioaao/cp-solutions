#include <iostream>
#include <algorithm>

using namespace std;

inline int getcd(int x){
  if(x == 0) return 1;
  int amt = 0;
  while(x > 0) amt++, x /= 10;
  return amt;
}
int main(){
  ios_base::sync_with_stdio(false);
  int amt[5] = {0,0,0,0,0}, n, x;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    amt[getcd(x)]++;
  }
  for(int i = 0; i < 5; i++) cout << amt[i] << ' ' ;
  cout << endl;
}
