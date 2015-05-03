#include <bits/stdc++.h>

#define MAXN 100100

using namespace std;

typedef long long L;

struct node{
  L cnt[3];
  int lazy;
  
  void clear(){
    for(int i = 0; i < 3; i++) cnt[i] = 0;
    lazy = 0;
  }
  
  node(){
    clear();
  }
};

node st[8*MAXN];
int v[MAXN], s[MAXN];
int n;

#define cl(x) ((x)<<1)
#define cr(x) (((x)<<1)+1)

void build(int x, int l, int r){
  st[x].clear();

  if(l == r)
    st[x].cnt[s[l]] = 1;
  else{
    build(cl(x), l, (l+r)/2);
    build(cr(x), (l+r)/2 + 1, r);

    for(int i = 0; i < 3; i++)
      st[x].cnt[i] = st[cl(x)].cnt[i] + st[cr(x)].cnt[i];
  }
}

void relax(int x, int l, int r){
  if(st[x].lazy == 0) return;
  
  node novo;
  novo.clear();

  for(int i = 0; i < 3; i++)
    novo.cnt[(i + st[x].lazy)%3] = st[x].cnt[i];
  
  if(l != r){
    st[cl(x)].lazy = (st[cl(x)].lazy + st[x].lazy)%3;
    st[cr(x)].lazy = (st[cr(x)].lazy + st[x].lazy)%3;
  }
  
  st[x] = novo;
}

void update(int x, int l, int r, int ii, int jj, int val){
  relax(x, l, r);
  
  if(l >= ii && r <= jj){
    st[x].lazy = val;
    relax(x,l,r);
    return ;
  }

  if(l > jj || r < ii) return ;

  update(cl(x), l, (l+r)/2, ii, jj, val);
  update(cr(x), (l+r)/2 + 1, r, ii, jj, val);

  for(int i = 0; i < 3; i++)
    st[x].cnt[i] = st[cl(x)].cnt[i] + st[cr(x)].cnt[i];
}

node query(int x, int l, int r, int ii, int jj){
  relax(x, l, r);

  if(l >= ii && r <= jj) return st[x];
  if(l > jj || r < ii) return node();

  node a = query(cl(x), l, (l+r)/2, ii, jj),
    b = query(cr(x), (l+r)/2+1, r, ii, jj);

  node ret;
  ret.clear();
  for(int i = 0; i < 3; i++)
    ret.cnt[i] = a.cnt[i] + b.cnt[i];
  
  return ret;
}

int get_v(int pos){
  node x = query(1, 0, n-1, pos, pos);
  for(int i = 0; i < 3; i++) if(x.cnt[i]) return i;
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q;
  string line;

  cin >> n >> q;
  cin >> line;

  for(int i = 0; i < n; i++){
    v[i] = (line[i] - '0')%3; // sempre positivo < 3
    s[i] = (v[i] + (i > 0 ? s[i-1] : 0)) % 3; // sempre positivo < 3
  }

  build(1, 0, n-1);

//   for(int k = 0; k < 3; k++, cout << '\n'){
//     cout << k << ':';
//     for(int i = 0; i < n; i++)
//       cout << query(1, 0, n-1, i,i).cnt[k] << ' ';
//   }

  int typ, a, b;
  while(q--){
    cin >> typ >> a >> b;
    
    if(typ == 1){
      a--;
      update(1, 0, n - 1, a, n - 1, (b - v[a] + 3)%3);
      v[a] = b % 3;
    }
    else{
      a--, b--;
      int tmp;
      if(a > 0){
	tmp = get_v(a-1);
	update(1, 0, n-1, a, b, 3-tmp);
      }
      
      node x = query(1, 0, n - 1, a, b);

      if(a > 0)
	update(1, 0, n-1, a, b, tmp);

      L ans = x.cnt[0];
      
      for(int i = 0; i < 3; i++) if(x.cnt[i] > 1){
	ans += (x.cnt[i] * (x.cnt[i]-1))/2;
      }

      cout << ans << '\n';
    }
  }      
}
