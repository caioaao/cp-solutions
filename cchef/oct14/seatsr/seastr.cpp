#include <bits/stdc++.h>

#define MAXN 100001
#define MAXK 101
#define INF 1e4

using namespace std;

int memo[MAXN][MAXK*2];
string s, w;
int t, k, a, b, n, m;


int editDist(){
  memo.clear();
  int ni, nj;
  memo[ii(n,m)] = 0;
  memo[ii(n-1,m)] = memo[ii(n,m-1)] = a;
  
  for(int i = n-1; i >= 0; i --){
    for(int j = min(m-1, i+k); j >= 0; j--){
      //cout << '(' << i << ' ' << j << ") = ";
      if(abs(i-j) > k) {
        //cout << "INF\n";
        break;
      }
      
      memo[ii(i,j)] = INF;
      int & res = memo[ii(i,j)];

      ni = i+1; nj = j;
      if(memo.count(ii(ni,nj))) res = min(res, memo[ii(ni,nj)] + a);

      ni = i; nj = j+1;
      if(memo.count(ii(ni,nj))) res = min(res, memo[ii(ni,nj)] + a);
      
      ni = i + 1; nj = j + 1;
      if(memo.count(ii(ni,nj))) res = min(res, memo[ii(ni,nj)] + (s[i] != w[j])*b);
      //cout << res << '\n';
    }
  }
  return memo.count(ii(0,0)) ? memo[ii(0,0)] : INF;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> t;
  while(t--){
   cin >> s >> w;
   cin >> a >> b >> k;
   if(a == 0 || b == 0){
     cout << "0\n";
     continue;
   }
   b = min(a*2,b);
   n = s.size(); m = w.size();
   int res = editDist();
   //cout << res << '\n';
   cout << (res <= k ? res : -1) << '\n';
  }
}
