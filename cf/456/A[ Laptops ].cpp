#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<ii> vals;
int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n){
    vals.assign(n,ii());
    for(int i = 0; i < n; i++){
      cin >> vals[i].first >> vals[i].second;
      vals[i].second *= -1;
    }
    vector<ii>::iterator it;
    sort(vals.begin(), vals.end());
    int smallest = -vals[n-1].second;
    for(int i = n-2; i >= 0; i--){
      if(-vals[i].second > smallest){
        cout << "Happy Alex\n";
        goto fim;
      }
      else{
        smallest = -vals[i].second;
      }
    }
    
    cout << "Poor Alex\n";
    fim:
    continue;
  }
}
