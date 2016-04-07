#include <bits/stdc++.h>

using namespace std;

vector<int> beg, end, vals;


int main(){
  ios_base::sync_with_stdio(false);
  
  int n, ans;
  while(cin >> n){
    beg.clear();
    end.clear();
    vals.assign(n,0);
    
    ans = 0;
    
    cin >> vals[0];
    beg.push_back(0);
    
    for(int i = 1; i < n; i++){
      cin >> vals[i];
      if(vals[i] <= vals[i-1]){
	end.push_back(i-1);
	ans = max(ans, end.back() - beg.back() + 1);
	beg.push_back(i);
      }
    }
    
    end.push_back(n-1);
    
    ans = max(ans, end.back() - beg.back() + 1);
    
    if(ans < n) ans++;
    
    //~ cout << beg.size() << &#39; &#39; << end.size() << endl;
    //~ for(int i = 0; i < beg.size(); i++) cout << beg[i] << &#39; &#39; << end[i] << endl;
    
    for(int i = 0; i < ((int)end.size())-1; i++){
      int s1 = end[i] - beg[i] + 1,
	  s2 = end[i+1] - beg[i+1] + 1,
	  lim1, lim2;
      
      if(s1 == 1 || s2 == 1) continue;
      
      lim1 = vals[end[i]-1];
      lim2 = vals[beg[i+1]+1];
      
      int lasti = vals[beg[i+1]]-1, begi1 = vals[end[i]] + 1;
      if(lasti > lim1 || begi1 < lim2){
	ans = max(ans, s1 + s2);
      }
    }
    
    cout << ans << &#39;\n&#39;;
  }
}
