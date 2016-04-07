#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<ii> vals;
int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin>>n){
    vals.assign(n,ii());
    for(int i = 0; i < n; i++){
      cin >> vals[i].first;
      vals[i].second = i;
    }
    
    sort(vals.begin(), vals.end());
    
    bool hasI = false;
    
    int f = 0, l = 0;
    
    for(int i = 0; i < n; i++){
      if(vals[i].second != i){
        // um pedaco ja foi virado
        if(hasI == true){
          cout << "no\n";
          goto cont;
        }
        
        int j = vals[i].second;
        for(int k = i; k <= vals[i].second; k++, j--){
          if(vals[k].second != j){
            cout << "no\n";
            goto cont;
          }
        }
        hasI = true;
        f = i; l = vals[i].second;
        i = vals[i].second+1;
      }
    }
    cout << "yes\n" << f+1 << &#39; &#39; << l+1 << &#39;\n&#39;;
    
    cont:
    continue;
  }
}
