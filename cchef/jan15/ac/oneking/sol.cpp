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

vector<ii> kis;

void solve(){
  int n;
  cin >> n;
  kis.assign(n, ii());

  for(int i = 0; i < n; i++){
    cin >> kis[i].ss >> kis[i].ff;
  }
  sort(kis.begin(), kis.end());
  L ans = 0;
  L las = -1;
  for(int i = 0; i < n; i++){
    if(las >= kis[i].ss) continue;
    las = kis[i].ff;
    ans++;
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  
  cin >> T;
  while(T--){
    solve();
  }
}
