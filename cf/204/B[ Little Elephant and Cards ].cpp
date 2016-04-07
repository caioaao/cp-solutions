#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef map<int,int> mii;

mii downs, ups;
int n;

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> n){
    downs.clear();
    ups.clear();
    
    int a, b;
    
    int ma = -1, mi = n/2 + n%2;
    
    for(int i = 0; i < n; i++){
      cin >> a >> b;
      if(!ups.count(a)) ups[a] = 0;
      if(!downs.count(a)) downs[a] = 0;
      if(!downs.count(b)) downs[b] = 0;
      
      ups[a]++;
      
      if(b != a)
        downs[b]++;
        
      if(ups[a] + downs[a] >= mi) ma = max(ma, ups[a]);
      if(ups[b] + downs[b] >= mi) ma = max(ma, ups[b]);
    }
    
    if(ma == -1)
      cout << "-1\n";
    else
      cout << max(0, n/2 + n%2 - ma) << &#39;\n&#39;;
  }
}
