#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX_N 100005
using namespace std;
typedef vector<int> vi;
typedef long long ll;

vi AdjList, visited;
int n;

inline ll pot(int a, int b) {
	ll x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=(x*y);
      if(x > MOD) x %= MOD;
		}
		y = (y*y);
    if(y > MOD) y %= MOD;
		b /= 2;
	}
	return x;
}


int get_cyc_size(int u){
  int s = 1;
  int p = AdjList[u];
  visited[u] = 1;
  while(p != u){
    visited[p] = 1;
    s++; p = AdjList[p];
  }
  return s;
}

vi primes, isPrime, pf;

void markP(int x){
  primes.push_back(x);
  for(int i = x+x; i < (int)isPrime.size(); i+=x) isPrime[i] = 0;
}
void seive(){
  isPrime.assign(MAX_N, 1);
  markP(2);
  for(int i = 3; i < (int)isPrime.size(); i++)
    if(isPrime[i])
      markP(i);
}

void addPfs(int x){
  int pot;
  for(int i = 0; x > 1; i++){
    pot = 0;
    while(x%primes[i] == 0)pot++, x/=primes[i];
    pf[i] = max(pf[i],pot);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  seive();
  while(t--){
    cin >> n;
    AdjList.assign(n,0);
    for(int i = 0; i < n; i++){
      cin >> AdjList[i];
      AdjList[i]--;
    }
    visited.assign(n,0);
    pf.assign(primes.size(),0);
    for(int i = 0; i < n; i++) if(!visited[i]){
      addPfs(get_cyc_size(i));
    }
    
    ll ans = 1;
    for(int i = 0; i < (int)primes.size(); i++){
      ans *= pot(primes[i],pf[i]);
      if(ans > MOD)
        ans %= MOD;
    }
    
    cout << ans << '\n';
  }
}
