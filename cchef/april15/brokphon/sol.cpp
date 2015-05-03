#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  int a0;
  int a;
  int n;
  cin >> t;
  while(t--){
      cin >> n;
      cin >> a0;
      --n;
      int ans = 0;
      bool cnt = false;
      while(n--){
          cin >> a;
          if(a != a0){
              ans += 1 + !cnt;
              cnt= true;
          }
          else{
              cnt = false;
          }
          a0 = a;
      }
      cout << ans << '\n';
  }
}
