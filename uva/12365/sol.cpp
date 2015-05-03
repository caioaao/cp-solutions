#include <bits/stdc++.h>

#define MAX_L 100001

using namespace std;
typedef long long ll;

ll st[20*MAX_L], pots[MAX_L], pots_i[MAX_L], b, p, l, n, inv_b;
  
ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}


#define cl(x) (x)*2
#define cr(x) ((x)*2) + 1

void build(int node, int L, int R){
  st[node] = 0;
  if(L < R){
    build(cl(node), L, (L+R)/2);
    build(cr(node), (L+R)/2 + 1, R);
  }
}

void update(int node, int L, int R, int i, ll v){
  if(i < L || i > R) return ;
  if(L == R) st[node] = v*pots[l-i-1];
  else{
    update(cl(node), L, (L+R)/2, i, v);
    update(cr(node), (L+R)/2 + 1, R, i, v);
    st[node] = st[cl(node)] + st[cr(node)];
  }
  if(st[node] > p) st[node] %= p;
}

ll query(int node, int L, int R, int i, int j){
  if(j < L || i > R) return 0;
  
  if( L >= i && R <= j){
    return st[node];
  }
  else{
    return (query(cl(node), L, (L+R)/2, i, j) + query(cr(node), (L+R)/2+1, R, i, j))%p;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(true){
    cin >> b >> p >> l >> n;
    if(b == 0) break;
    inv_b = mul_inv(b,p);
    pots[0] = 1;
    pots_i[0] = 1;
    for(int i = 0; i < l; i++){
      pots[i+1] = pots[i]*b;
      if(pots[i+1] > p) pots[i+1]%=p;
      
      pots_i[i+1] = pots_i[i]*inv_b;
      if(pots_i[i+1] > p) pots_i[i+1]%=p;
      //~ cout << pots[i+1] << ',' << pots_i[i+1] << '\n';
    }
    build(1, 0, l-1);
    ll i, v, j, q;
    char cm;
    while(n--){
      cin >> cm >> i;
      //~ cout << cm << ':';
      if(cm == 'E'){
        cin >> v;
        update(1,0,l-1,i-1,v);
        //~ cout << '-' << query(1,0,l-1,i-1,i-1) << endl;
      }
      else{
        cin >> j;
        q = (query(1,0,l-1,i-1,j-1)*pots_i[l-j])%p;
        cout << q << '\n';
      }
    }
  
    cout << "-\n";
  }
}
