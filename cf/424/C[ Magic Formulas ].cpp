#include <bits/stdc++.h>

using namespace std;

int xorUpToK(int k) {
	switch (k % 4) {
		case 0: return k;
		case 1: return 1;
		case 2: return k + 1;
		case 3: return 0;
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, x, ans = 0;
  
  cin >> n;
  
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    ans ^= x;
  }
  
  for(int i = 1; i <= n; i++){
    ans ^= xorUpToK(n%i);
    if((n/i)%2) ans ^= xorUpToK(i-1);
  }
  cout << ans << &#39;\n&#39;;
}
