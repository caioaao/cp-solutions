#define DEBUG
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

  int T;
  int n, x, y, k, p, c;
  int bestC;

  cin >> T;
  while(T--){
    cin >> x >> y >> k >> n;
    bestC = 0;
    while(n--){
      cin >> p >> c;
      if(c <= k) bestC = max(bestC, p);
    }
    if(y + bestC >= x)
      cout << "LuckyChef\n";
    else
      cout << "UnluckyChef\n";
  }      
}
