#include <bits/stdc++.h>

#define mod 1000000007
#define MAX_Q 100002

using namespace std;
typedef long long ll;

typedef pair<ll,ll> ii;


string s;
int q, lq[10];
vector<string> qs;
vector<ii> memo;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define cl(x) 2*(x)
#define cr(x) 2*(x)+1

int qp[4*MAX_Q][10], lazy[4*MAX_Q][10];

void build(){
  memset(qp,0,sizeof qp);
  memset(lazy,0,sizeof lazy);
}

void relax(int x, int l, int r){
  for(int i = 0; i < 10; i++) if(lazy[x][i]){
    qp[x][i] = lazy[x][i];
    if(l != r){
      lazy[cl(x)][i] = lazy[x][i];
      lazy[cr(x)][i] = lazy[x][i];
    }
    lazy[x][i] = 0;
  }
}

void update(int x, int i, int j, int l, int r, int d, int v){
  relax(x,l,r);
  if(i > r || j < l) return;
  
  if(i <= l && j >= r){
    lazy[x][d] = v;
    relax(x,l,r);
    
    return;
  }
  
  update(cl(x), i, j, l, (l+r)/2, d, v);
  update(cr(x), i, j, (l+r)/2+1, r, d, v);
  
  if(qp[cl(x)][d] == qp[cr(x)][d])
    qp[x][d] = qp[cl(x)][d];
  else
    qp[x][d] = -1;
}

int query(int x, int l, int r, int k, int d){
  relax(x,l,r);
  if(r < k || l > k) return -1;
  if(qp[x][d] != -1){
    return qp[x][d];
  }
  int a = query(cl(x), l, (l+r)/2, k, d);
  if(a != -1) return a;
  else return query(cr(x), (l+r)/2+1, r, k, d);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

ii calc(int q_id){
  if(memo[q_id].second != -1) return memo[q_id];
  
  memo[q_id].first = 0;
  memo[q_id].second = 1;
  for(int i = qs[q_id].size()-1; i >= 0 ; i--){
    int nq = query(1, 0, q, q_id, qs[q_id][i]-&#39;0&#39;);
    if(nq){
      memo[q_id].first = (memo[q_id].first + memo[q_id].second*calc(nq).first)%mod;
      memo[q_id].second = (calc(nq).second*memo[q_id].second)%mod;
    }
    else{
      memo[q_id].first = (memo[q_id].first + memo[q_id].second*(qs[q_id][i]-&#39;0&#39;))%mod;
      memo[q_id].second = ((memo[q_id].second)*10)%mod;
    }
  }
  return memo[q_id];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  
  string l;
  cin >> l;
  cin >> q;
  
  qs.assign(q+1,string());
  qs[0] = l;
  
  memo.assign(q+1, ii(-1,-1));
  
  memset(lq,0,sizeof lq);
  
  build();
  
  int d;
  
  getline(cin,l);
  
  for(int i = 1; i <= q; i++){
    getline(cin,l);
  
    if(l.size() == 0){
      i--;
      continue;
    }
    d = l[0] - &#39;0&#39;;
    if(l.size() > 3)
      qs[i] = l.substr(3);
  
    //~ cout << d << "->" << qs[i] << &#39;\n&#39;;
    update(1, lq[d], i-1, 0, q, d, i);
    
    lq[d] = i;
  }
  cout << calc(0).first << &#39;\n&#39;;
}
