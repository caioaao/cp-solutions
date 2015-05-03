#include <bits/stdc++.h>

#define mod 1000000007
#define max_d 101

using namespace std;
typedef long long ll;

ll f[max_d][2][1<<10];
int b[max_d], n;

ll prec(int id, bool eq, bool bm){
  if(id == n) return 1;
  if(f[id][eq][bm] != -1) return f[id][eq][bm];
  f[id][eq][bm] = 0;
  int e;
  if(eq) e = b[id];
  else e = 10;
  for(int i = 0; i < e; i++){
    f[id][eq][bm] += prec(id+1,0,bm | (1<<i));
    if(f[id][eq][bm] >= mod) f[id][eq][bm] -= mod;
  }
  if(eq){
    f[id][eq][bm] += prec(id+1,1,bm|(1 << b[id]));
    if(f[id][eq][bm] >= mod) f[id][eq][bm] -= mod;
  }
  return f[id][eq][bm];
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  
}
