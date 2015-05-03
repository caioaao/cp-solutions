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

L nS, nC;

L amts[110];

void dc(int freq)
{
  if(freq > nS) return;

  dc(freq + 1);
  
  for(int i = 0; i <= 100; i++)
    amts[i] *= 2;
  
  // se tem cosseno passando pelo meio
  if(freq > 1 && nC >= freq - 1)
    amts[nS - freq + 2]++;
  else
    amts[nS - freq + 1]++;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  L T;
  L k;
  cin >> T;
  while(T--){
    cin >> nS >> nC >> k;

    memset(amts, 0, sizeof(amts));
    if(nS > 0){
        dc(1);
    
        amts[nS] += 2;
    }

    for(int i = max(1LL,nS); i <= nC; i++)
      amts[1] += (1LL << i);
    
    L ans = 0;
    for(int i = k; i <= 100; i++) ans += amts[i];
    cout << ans << '\n';
  }
}
