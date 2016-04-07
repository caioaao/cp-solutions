#include <bits/stdc++.h>

#define MAX_N 100001

using namespace std;
typedef long long ll;

ll vals[MAX_N], vc[MAX_N];
ll n,m,w, be;
deque<ll> q;
bool check(ll x){
     while(!q.empty()) q.pop_back();
     ll amt = 0, delt = 0, d;
     
     for(int i = 0; i < n; i++){
             while(!q.empty() && q.front() + w <= i){
                 delt -= vc[q.front()];
                 q.pop_front();
             }
             d = x - (vals[i] + delt);
             if(d <= 0) continue;
             q.push_back(i);
             vc[i] = d;
             amt += d;
             delt += d;
     }
     
     return amt <= m;
}

ll bs(){
     ll lo = be, hi = be + m, mi, ans = be;
     while(lo <= hi){
              mi = (lo+hi)/2;
              if(check(mi)){
                  lo = mi+1;          
                  ans = max(ans,mi);
              }
              else{
                   hi = mi-1;
              }
     }
     return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    while(cin >> n >> m >> w){
              cin >> vals[0];
              be = vals[0];
              for(int i = 1; i < n; i++){
                      cin >> vals[i];
                      be = min(vals[i],be);
              }
              cout << bs() << &#39;\n&#39;;
    }
}
