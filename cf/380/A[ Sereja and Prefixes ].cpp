#include <bits/stdc++.h>

#define MAX_L 100005

using namespace std;
typedef long long ll;

struct query{
  ll t, x, c;
  query():t(0),x(0),c(0){}
  query(ll _t, ll _x, ll _c):
    t(_t), x(_x), c(_x){ }
};

vector<ll> vals, len;
vector<query>q;

ll memo[MAX_L];

ll n, m;

ll bt(ll id){
  if(id < MAX_L) return memo[id];
  
  // nunca vai ser < 0, ja que id > 0 e len[0] = 0
  ll qid = lower_bound(len.begin(), len.end(), id) - len.begin() - 1;
    //~ cout << id << &#39;:&#39; << len[qid+1] << &#39;,&#39; << qid <<endl;
  
  if(q[qid].t == 1) return q[qid].x;
  else{
    // len[qid] eh o primeiro len menor que id
    id = id-len[qid];
    if(id > q[qid].x) {
      ll nid = id%q[qid].x;
      id = nid == 0 ? q[qid].x : nid;
    }
    return memo[id];
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> m){
    q.assign(m,query());
    len.assign(m+1,0);
    
    n = 0;
    
    for(int i = 0; i < m; i++){
      cin >> q[i].t >> q[i].x;
      if(q[i].t == 1){
        len[i+1] = ++n;
        if(n < MAX_L)memo[n] = q[i].x;
      }
      else{
        cin >> q[i].c;
        
        for(ll k = n+1, cnt = 0; cnt < q[i].c && k < MAX_L; cnt++){
          for(ll j = 1; j <= q[i].x && k < MAX_L; j++, k++){
            //~ cout  << cnt << &#39;,&#39; << k << &#39;:&#39; << j << endl;
            memo[k] = memo[j];
          }
        }
        
        n += q[i].x*q[i].c;
        len[i+1] = n;
      }
    }
    //~ for(int i = 0; i < n; i++) cout << memo[i] << &#39; &#39;;
    //~ cout << endl;
    cin >> n;
    ll x;
    bool first = true;
    while(n--){
      if(!first) cout << &#39; &#39;;
      first = false;
      cin >> x;
      cout << bt(x);
    }
    cout << &#39;\n&#39;;
  }
}
