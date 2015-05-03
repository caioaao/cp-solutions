#include <bits/stdc++.h>


using namespace std;
typedef long long L;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  L n, b_i;
  cin >> T;
  while (T--) {
    cin >> n;
    L acc = 0;
    bool ok = 1, big = 0;
    L new_n = n;
    for (int i = 0; i < n; i++) {
      cin >> b_i;
      acc += b_i;

      if(b_i > 100)
	ok = 0;
      if(b_i == 0) new_n--;
    }
    n = new_n;
    if(ok && acc >= 100 && acc < 100 + n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
