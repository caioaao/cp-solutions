#include <bits/stdc++.h>

#define MAX_N 100001
#define MAX_X 5001

using namespace std;
vector<int> vals;
int amt[MAX_X];
int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n){
    vals.clear();
    memset(amt, 0, sizeof amt);
    int x;
    for(int i = 0; i < n; i++){
      cin >> x;
      if(amt[x] < 2){
        amt[x]++;
        vals.push_back(x);
      }
    }
    sort(vals.begin(), vals.end());
    if(amt[vals.back()] > 1) vals.pop_back();
    cout << vals.size() << &#39;\n&#39;;
    bool first = true;
    for(int i = 0; i < (int)vals.size(); i+=2){
      if(!first) cout << &#39; &#39;;
      first = false;
      cout << vals[i];
    }
    for(int i = (int)vals.size() - (vals.size() % 2 == 0 ?  1 : 2); i >= 0; i-=2){
      if(!first) cout << &#39; &#39;;
      first = false;
      cout << vals[i];
    }
    cout << &#39;\n&#39;;
  }
}
