#include <bits/stdc++.h>

using namespace std;

inline void scan_f(int &x) {
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

int A[4000100][12], st[4000100][12], lazy[4000100];
/////////////////////////////////////////
/////////////////////////////////////////
int pots[5] = {1,10,100,1000,10000};

inline int getcd(int x){
  if(x == 0) return 1;
  int amt = 0;
  while(x > 0) amt++, x /= 10;
  return amt;
}

inline int get_alg(int x, int i){
  return (x/pots[i]) - (x/pots[i+1])*10;
}

inline int rot(int x, int nb, int cd){
  if(nb == 0) return x;
  int ret = 0;
  for(int pot = pots[cd-1], i = nb; pot > 0; pot /= 10, i = (i == cd-1 ? 0 : i+1)){
    ret += pot * get_alg(x, cd - i - 1);
  }
  
  return ret;
}


inline void fillA(int x, int id){
  int cd = getcd(x);
  for(int i = 0; i < cd; i++)
    A[id][i] = rot(x,i,cd);
  for(int i = cd; i < 12; i++)
    A[id][i] = A[id][i%cd];
}
int ant[12];
inline void rotArr(int *ori, int b){
  //~ assert(b >= 0 && b < 12);
  
  for(int i = 0; i < 12; i++)ant[i] = ori[i];
  for(int i = b, j = 0; j < 12; j++){
    ori[j] = ant[i];
    if(++i == 12) i = 0;
  }
}
/////////////////////////////////////////
/////////////////////////////////////////


///////////////////////////////////////
///////////////TREE
///////////////////////////////////////

#define cl(x) (x)*2
#define cr(x) (x)*2+1


void build(int x, int l, int r){
  lazy[x] = 0;
  if(l == r){
    for(int i = 0; i < 12; i++)
      st[x][i] = A[l][i];
    return ;
  }
  build(cl(x), l, (l+r)/2);
  build(cr(x), (l+r)/2+1,r);
  for(int i = 0; i < 12; i++){
    st[x][i] = max(st[cl(x)][i],st[cr(x)][i]);
  }
}

inline void relax(int x, int l, int r){
  if(lazy[x] == 0) return ;
  else{
    if(l != r){
      lazy[cl(x)] += lazy[x];
      if(lazy[cl(x)] >= 12) lazy[cl(x)] -= 12;
      
      lazy[cr(x)] += lazy[x];
      if(lazy[cr(x)] >= 12) lazy[cr(x)] -= 12;
    }
    
    rotArr(st[x],lazy[x]);
    lazy[x] = 0;
  }
}

void update(int x, int l, int r, int i, int j, int val){
  relax(x,l,r);
  if(r < i || l > j) return ;
  
  if(l == r){
    rotArr(st[x],val);
    return ;
  }
  
  if(l >= i && r <= j){
    lazy[x] = val;
    relax(x,l,r);
    return;
  }
  
  update(cl(x),l,(l+r)/2,i,j,val);
  update(cr(x),(l+r)/2+1,r,i,j,val);
  for(int i = 0; i < 12; i++){
    st[x][i] = max(st[cl(x)][i],st[cr(x)][i]);
  }
}

int query(int x, int l, int r, int i, int j){
  if(r < i || l > j) return -100000;
  
  if(l >= i && r <= j){
    return st[x][lazy[x]];
  }
  
  relax(x,l,r);
  return max(query(cl(x), l,(l+r)/2,i,j),
	      query(cr(x),(l+r)/2+1,r,i,j));
}

///////////////////////////////////////
/////////////// end TREE
///////////////////////////////////////




int main(){
  int n,m,x, qt, l, r;
  scan_f(n);
  for(int i = 0; i < n; i++){
    scan_f(x);
    fillA(x, i);
  }
  build(1,0,n-1);
  scan_f(m);
  while(m--){
    scan_f(qt);
    scan_f(l);
    scan_f(r);
    if(qt == 0){
      scan_f(x);
      update(1,0,n-1,l,r,(x >= 12 ? x%12 : x));
    }
    else{
      printf("%d\n",query(1,0,n-1,l,r));
    }
  }
}
