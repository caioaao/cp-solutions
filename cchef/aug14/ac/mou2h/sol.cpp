#include <stdio.h>
#include <string.h>

#define MOD 1000000009
#define MAX_H 4000001
#define MAX_N 1000001

using namespace std;

inline void Scan_f(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

int n, t, lsoma, dp, d, lst, x;
int last[2*MAX_H];
int ltc[2*MAX_H];

int main(){
  Scan_f(t);
  memset(ltc,-1,sizeof ltc);
  while(t--){
    Scan_f(n);
    lsoma = 1;
    n--;
    Scan_f(lst);
    for(int i = 1; i <= n; i++){
      Scan_f(d);
      
      x = d - lst;
      lst = d;
      
      dp = lsoma - (ltc[x + MAX_H] == t ? last[x + MAX_H] : 0);
      if(dp >= MOD) dp -= MOD;
      else if(dp <= -MOD) dp += MOD;
      
      last[x + MAX_H] = lsoma;
      ltc[x + MAX_H] = t;
      
      lsoma += dp;
      
      if(lsoma >= MOD) lsoma -= MOD;
      else if(lsoma <= -MOD) lsoma += MOD;
    }
    --lsoma;
    
    if(lsoma >= MOD) lsoma -= MOD;
    else if(lsoma <= -MOD) lsoma += MOD;
    if(lsoma < 0) lsoma += MOD;
    
    printf("%d\n", lsoma);
  }
}
