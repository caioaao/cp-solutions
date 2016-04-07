#include <bits/stdc++.h>

#define MAX_N 100000
#define CL(x) 2*(x)
#define CR(x) 2*(x) + 1

using namespace std;
typedef long long ll;

int n, m, color[MAX_N*20], beg[MAX_N];
ll soma[MAX_N*20],lazy_s[MAX_N*20];

void build(int node, int L, int R){
  lazy_s[node] = 0;
  soma[node] = 0;
  
  color[node] = 0;
  
  if(L == R){
    color[node] = beg[L];
    return ;
  }
  
  build(CL(node), L, (L+R)/2);
  build(CR(node), (L+R)/2 + 1, R);
}


void relax(int node, int L, int R){
  if(lazy_s[node] == 0)
    return;
  
  soma[node] += (R-L+1)*lazy_s[node];
  if(L != R){
    lazy_s[CL(node)] += lazy_s[node];
    lazy_s[CR(node)] += lazy_s[node];
    
    color[CL(node)] = color[CR(node)] = color[node];
  }
  
  lazy_s[node] = 0;
}

ll query(int node, int qL, int qR, int L, int R){
  relax(node, L, R);
  if(R < qL || L > qR)
    return 0;
  
  if(L >= qL && R <= qR)
    return soma[node];
    
  return query(CL(node), qL, qR, L, (L+R)/2) + query(CR(node), qL, qR, (L+R)/2 + 1, R);
}

void update(int node, int qL, int qR, int L, int R, int c){
  relax(node, L, R);
  if(R < qL || L > qR)
    return ;
  if(L == R){
    soma[node] += abs(color[node] - c);
    color[node] = c;
  }
  else if(L >= qL && R <= qR && color[node] != 0){
    //significa que todos abaixo têm a mesma cor
    ll delta = abs(color[node]-c);
    soma[node] += (R-L+1)*delta;
    color[node] = c;

    lazy_s[CL(node)] += delta;
    lazy_s[CR(node)] += delta;
    
    color[CL(node)] = color[CR(node)] = c;
  }
  else{
    update(CL(node), qL, qR, L        , (L+R)/2, c);
    update(CR(node), qL, qR, (L+R)/2+1, R      , c);
    
    soma[node] = soma[CL(node)] + soma[CR(node)];
    
    if(color[CL(node)] == color[CR(node)]) 
      color[node] = color[CL(node)];
    else
      color[node] = 0;
  }
}

int main(){
  while(cin >> n >> m){
    for(int i = 0; i < n; i++) beg[i] = i+1;
    build(1, 0, n-1);
    int typ, le, ri, x;
    while(m--){
      cin >> typ >> le >> ri;
      if(typ == 1){
        cin >> x;
        update(1,le-1,ri-1,0,n-1,x);
      }
      else{
        cout << query(1, le-1, ri-1, 0, n-1) << &#39;\n&#39;;
      }
    }
  }
}
