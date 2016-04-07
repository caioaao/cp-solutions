#include <bits/stdc++.h>

#define MAX_L 100001

using namespace std;
typedef long long ll;

struct line{
  ll m,b;
  line(){}
  line(ll m_, ll b_):m(m_), b(b_){ }
};

// testa se line 2 eh irrelevante
bool irrelevant(line l1, line l2, line l3){
  return (l3.b - l1.b)/(double)(l1.m - l3.m) < (l2.b - l1.b)/(double)(l1.m - l2.m);
}

line lines[MAX_L];
int hbl;

void add_line(ll m, ll b){
  line curr(m,b);
  
  while(hbl >= 2 && irrelevant(lines[hbl-2],lines[hbl-1], curr)){
    hbl--;
  }
  lines[hbl++] = curr;
}

int pointer;
ll query(ll x){
  if(pointer >= hbl){
    pointer = hbl-1;
  }
  while(pointer < hbl-1 && lines[pointer+1].m*x + lines[pointer+1].b <= lines[pointer].m*x + lines[pointer].b )
    pointer++;
  return lines[pointer].m*x + lines[pointer].b;
}

ll hs[100001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  
  ll c;
  cin >> n;
  
  for(int i = 0; i < n; i++) cin >> hs[i];
  
  ll ans;
  cin >> c;
  hbl = 0;
  add_line(c,0);
  pointer = 0;
  for(int i = 1; i < n; i++){
    cin >> c;
    ans = query(hs[i]);
    add_line(c,ans);
  }
  
  cout << ans << &#39;\n&#39;;
}
