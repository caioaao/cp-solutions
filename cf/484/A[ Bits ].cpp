#include <bits/stdc++.h>

#define ff first
#define ss second


using namespace std;
typedef long long ll;


inline int cnt(unsigned long long int i) {
    i = i - ((i >> 1) & 0x5555555555555555ULL);
    i = (i & 0x3333333333333333ULL) + ((i >> 2) & 0x3333333333333333ULL);
    return (int)((((i + (i >> 4ULL)) & 0xF0F0F0F0F0F0F0FULL) * 0x101010101010101ULL) >> 56);
}



ll memo[70][2][2];

ll L, R;
  
ll dp(int id, bool sm, bool gr){
  if(id < 0) return 0;
  
  ll & ans = memo[id][sm][gr];
  
  if(ans == -1){
    
    ans = 0;
    ll hbit = (R & (1ll<<id)) != 0,
       lbit = (L & (1ll<<id)) != 0;
       
    ll lb, hb;
    
    if(sm) hb = 1;
    else hb = hbit;
    
    if(gr) lb = 0;
    else lb = lbit;
    
    
    ll ret;
    
    for(ll bit = lb; bit <= hb; bit++){
      bool nsm, ngr;
      
      if(sm || bit < hbit) nsm = 1;
      else nsm = 0;
      
      if(gr || bit > lbit) ngr = 1;
      else ngr = 0;
      
      ret = dp(id-1, nsm, ngr) | (bit << id);
      if(cnt(ret) > cnt(ans)) ans = ret;
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  cin >> N;
  while(N--){
    cin >> L >> R;
    memset(memo,-1,sizeof memo);
    
    cout << dp(60,0,0) << &#39;\n&#39;;
  }
  
}
