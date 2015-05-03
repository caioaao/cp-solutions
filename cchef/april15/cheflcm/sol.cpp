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


L solve(L n)
{
    L ans = 0;
    int i;
    for(i = 1; i*i < n; ++i)if(n %i == 0){
        ans += i + n/i;
    }
    if(i * i == n) ans += i;

    return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  L n;
  cin >> t;
  while(t--){
      cin >> n;
      cout << solve(n) << '\n';
  }
}
