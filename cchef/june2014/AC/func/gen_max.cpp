#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll maxHi[65] = {0,9223372036854775807ll,3037000499ll,2097152,55108,6208,1448,512,234,128,78 ,52 ,38 ,28 ,22 ,18 ,15 ,13 ,11 ,9 ,8 ,8 ,7 ,6 ,6 ,5 ,5 ,5 ,4 ,4 ,4 ,4 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2,2,2,2,2,1};

inline ll fast_pow(ll a, ll b){
  ll result = 1;

  while (b){
    if (b%2==1){
      result *= a;
    }
    b /= 2;
    a *= a;
  }

  return result;
}

inline ll root(ll a, ll n)
{
  ll hi = maxHi[n],
    lo = 1, mi, aux;
  
  bool c = true;
  while(hi != lo && c == true){
    if(hi == lo+1) break;
    
    c = false;
    mi = (hi+lo)/2;
    aux = fast_pow(mi,n);
    if(aux > a){
      if(hi != mi) c = true;
      hi = mi;
    }
    else if(aux == a){
      return mi;
    }
    else{
      if(lo != mi) c = true;
      lo = mi;
    }
  }
  //~ if(hi != lo) cout << lo << ',' << hi << '.';
  if(fast_pow(hi,n) <= a){
    //~ cout << a << "^1/" << n << ',' << lo << ',' << hi << ' ' << fast_pow(hi,n) << endl;
    return hi;
  }
  //~ cout << endl;
  return lo;
}

int main(){
  int amt[60][50];
  memset(amt,0,sizeof amt);
  for(int i = 1; i < 200; i++){
    for(int j = 1; j < 60; j++){
      cout << root(i,j) << ' ';
      amt[j][root(i,j)]++;
    }
    cout << endl;
  }
  
  for(int i = 1; i < 60; i++){
    for(int j = 1; j < 50; j++) cout << amt[i][j] << ' ';
    cout << endl;
  }
}
