#include <bits/stdc++.h>

#define pb push_back
#define sz size

#define MAXA 1000005

using namespace std;
typedef long long ll;
typedef vector<int> vi;



bitset<MAXA> is_p;
vector<vi> primes;

void sieve(){
  is_p.set();
 
  is_p.reset(0); is_p.reset(1);
  
  primes.assign(MAXA,vi());
  
  for(int i = 2; i < MAXA; i++) if(is_p[i]){
    primes[i].pb(i);
    for(int j = i+i; j < MAXA; j+=i) is_p.reset(j), primes[j].pb(i);
  }
}

vi lst;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  sieve();
  
  int t, n, a;
  
  cin >> t;
  
  while(t--){
    cin >> n;
    lst.assign(MAXA, -1);
    int b = 0, bst = 1;
    
    for(int cur = 0; cur < n; cur++){
      cin >> a;
      
      for(int i = 0; i < (int)primes[a].sz(); i++){
        int pf = primes[a][i];
        b = max(b, lst[pf] + 1);
        
        lst[pf] = cur;
      }
      
      bst = cur - b + 1;
    }
    
    cout << (bst > 1 ? bst : -1) << '\n';
  }
}
