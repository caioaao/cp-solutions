#include <bits/stdc++.h>

using namespace std;
set<vector<int> > poss;
vector<int> vals;
int main(){
  int n;
  cin >> n;
  int last, x;
  cin >> last;
  for(int i = 1; i < n; i++){
    cin >> x;
    vals.push_back(x-last);
    last = x;
  }
  int ant;
  for(int bm = 1; bm < (1<<vals.size()); bm++){
    vector<int> s;
    for(int i = 0; i < (int)vals.size(); i++)if((1<<i) & bm){
      s.push_back(vals[i]);
    }
    ant = poss.size();
    poss.insert(s);
    if(ant != poss.size()){
      cout << poss.size() << ':';
      for(int i = 0; i < (int)s.size(); i++)
        cout << s[i] << ' ';
      cout << endl;
    }
  }
}
