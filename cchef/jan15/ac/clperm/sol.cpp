#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXK 101000

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

L ks[MAXK];
void solve(){
  L n, k;
  cin >> n >> k;

  for(int i = 0; i < k; i++) cin >> ks[i];
  sort(ks, ks+k);
  L Sn, St, Sk = 0;
  L ans = -1;
  for(int i = 0; i < k; i++){
    Sn = (ks[i]*(ks[i]-1))/2;
    St = Sn - Sk;
    if(St < ks[i]){
      ans = ks[i];
      break;
    }
    Sk += ks[i];
  }
  if(ans == -1){
    Sn = (n*(n+1))/2;
    ans = Sn-Sk+1;
  }

  cout << ((ans & 1) ? "Chef\n" : "Mom\n");
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
