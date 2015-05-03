#include <bits/stdc++.h>

#define MAX_N 100005

using namespace std;
typedef long long ll;

struct evt{
  int x;
  bool op;
  bool operator<(const evt &rhs) const{
    if(x < rhs.x) return false;
    if(x > rhs.x) return true;
    if(!op) return false;
    else return true;
  }
};


int perm[MAX_N], q[MAX_N];
priority_queue<evt> pq;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t, n, m;
  cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      cin >> perm[i];
      perm[i]--;
    }
    
    while(!pq.empty()) pq.pop();
    
    evt b, e;
    b.op = 1;
    e.op = 0;
    
    for(int i = 0; i < m; i++){
      cin >> b.x >> e.x;
      b.x--;
      pq.push(b);
      pq.push(e);
    }
    memset(q, -1, sizeof q);
    int lastO = -1, amtO = 0;
    evt curr;
    int i;
    for(i = 0; i < n; i++){
      while(!pq.empty() && pq.top().x <= i){
	curr = pq.top();pq.pop();
	//~ cout << curr.x << '-' << curr.op << endl;
	if(curr.op){
	  if(amtO++ == 0){
	    lastO = i;
	  }
	}
	else{
	  amtO--;
	}
      }
      if(perm[i] < i){
	if(amtO == 0 || lastO > i){
	  //~ cout << amtO << ' '<< lastO << ' ' << perm[i] << ' ' << i << '\n';
	  break;
	}
      }
      else if(perm[i] > i){
	q[perm[i]] = i;
      }
      if(q[i] != -1){
	if(amtO == 0 || lastO > q[i]){
	  //~ cout << amtO << ' '<< lastO << ' ' << q[i] << ' ' << i << '\n';
	  break;
	}
      }
    }
    if(i == n){
      cout << "Possible\n";
    }
    else{
      cout << "Impossible\n";
    }
  }
}
