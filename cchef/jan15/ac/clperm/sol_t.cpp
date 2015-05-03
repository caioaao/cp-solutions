#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXK 101000

#define MAXN 101000

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

L v[MAXK], v2[MAXN];
void solve(){
  L n,k;
  cin >> n >> k;
  for(int i = 0; i < k; i++)
    cin >>v[i];

  sort(v, v+k);

  int n2 = 0;

  for(int ptr = 0, x = 1; x <= n; x++){
    if(ptr < k && v[ptr] == x){
      ptr++;
    }
    else{
      v2[n2++] = x;
    }
  }

//  for(int i = 0; i < n2; i++) cout << v2[i] << ' ';
//  cout << endl;

  L soma = 0;
  L ans = -1;
  for(int i = 0; i < n2; i++){
    if(v2[i] > soma + 1){
      ans = soma + 1;
      break;
    }
    else{
      soma += v2[i];
    }
  }
  if(ans == -1) ans = soma + 1;
  cout << ans << ':';
  cout << (((ans)&1) ? "Chef\n" : "Mom\n");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
