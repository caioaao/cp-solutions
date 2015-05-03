#include <bits/stdc++.h>

using namespace std;

vector<int> frogs;
set<int> dists;
map<int,int> distInd;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n, k, p;
  cin >> n >> k >> p;
  
  frogs.assign(n,0);
  for(int i = 0; i < n; i++){
    cin >> frogs[i];
    dists.insert(frogs[i]);
  }
  
  set<int>::const_iterator it = dists.begin();
  distInd[*it] = 0;
  int last = *it, d;
  for(++it; it != dists.end(); ++it){
    d = *it - last;
    distInd[*it] = distInd[last] + (d > k);
    last = *it;
  }
  
  int a, b, m;
  for(int i = 0; i < p; i++){
    cin >> a >> b;
    a--; b--;
    if(frogs[a] > frogs[b]) swap(a,b);
    //~ cout << frogs[b] << ' ' << frogs[a] << endl;
    m = distInd[frogs[b]] - distInd[frogs[a]];
    //~ cout << m << ' ';
    if(m > 0) cout << "No\n";
    else      cout << "Yes\n";
  }
}
