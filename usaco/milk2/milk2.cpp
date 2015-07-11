/*
ID: caioaao
LANG: C++
TASK: milk2
*/

#include <bits/stdc++.h>

using namespace std;

#define L_BEG 0
#define L_END 1

struct evt{
  int id, typ, x;
  evt(){}
  evt(int _id, int _typ, int _x):id(_id), typ(_typ), x(_x){ }
};

bool cmp(evt a, evt b){
  if(a.x == b.x){
    if(a.typ == b.typ){
      return a.id < b.id;
    }
    return a.typ < b.typ;
  }
  return a.x < b.x;
}

vector<evt> evts;

int main(){
  freopen("milk2.in","rb",stdin);
  freopen("milk2.out","w",stdout);
  
  ios_base::sync_with_stdio(false);
  
  int n, l, h;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> l >> h;
    evts.push_back(evt(i,0,l));
    evts.push_back(evt(i,1,h));
  }
  sort(evts.begin(),evts.end(),cmp);
  
  int buff1 = 0, buff2 = 0, ans1 = 0, ans2 = 0, lx = evts[0].x, amto = 0;
  for(int i = 0; i < (int)evts.size(); i++){
    if(amto == 0){
      buff2 += evts[i].x-lx;
    }
    else{
      buff1 += evts[i].x-lx;
    }
    
    if(evts[i].typ == 0){
      if(++amto == 1){
        ans2 = max(ans2, buff2);
        buff2 = 0;
      }
    }
    else{
      if(--amto == 0){
        ans1 = max(ans1, buff1);
        buff1 = 0;
      }
    }
    
    lx = evts[i].x;
  }
  cout << ans1 << ' ' << ans2 << '\n';
}
