#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef set<iii>::const_iterator itsiii;

int v,e;
vector<vi> AdjList;
vi deleted;

int main(){
  ios_base::sync_with_stdio(false);
  
  viii tbd;
  while(cin >> v >> e){
    AdjList.assign(v,vi());
    deleted.assign(v,0);
    tbd.assign(v,iii(0,ii(0,0)));
    for(int i = 0; i < v; i++){
      cin >> tbd[i].first;
      tbd[i].second.second = i;
      tbd[i].first *= -1;
    }
    int a, b;
    for(int i = 0; i < e; i++){
      cin >> a >> b;
      a--; b--;
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
      tbd[a].second.first += -tbd[b].first;
      tbd[b].second.first += -tbd[a].first;
    }
    
    set<iii> pq;
    int ans = 0;
    for(int i = 0; i < v; i++) pq.insert(tbd[i]);
    while(!pq.empty()){
      //~ cout << "poss:";
      //~ for(itsiii it = pq.begin(); it != pq.end(); ++it){
        //~ cout << " (" << it->second.second+1 << &#39;,&#39; << it->second.first << &#39;)&#39;;
      //~ }
      //~ cout << endl;
      iii d = *pq.begin();
      //~ cout << "chose " << d.second.second+1 << &#39;,&#39; << d.second.first << endl;
      pq.erase(d);
      int u = d.second.second;
      deleted[u] = 1;
      for(int i = 0; i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(!deleted[v]){
          iii curr_v = tbd[v];
          pq.erase(curr_v);
          curr_v.second.first -= -d.first;
          tbd[v] = curr_v;
          pq.insert(curr_v);
        }
      }
      ans += d.second.first; 
    }
    cout << ans << &#39;\n&#39;;
  }
}
