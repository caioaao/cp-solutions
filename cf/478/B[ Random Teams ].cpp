#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll m,n, au, ma, mi;

int main(){
  ios_base::sync_with_stdio(false);
  
  while(cin >> n >> m){
    au = n-m+1;
    ma = (au*(au-1))/2;
    au = n/m;
    mi = m*((au*(au-1))/2);
    
    au = n%m;
    mi += au*(n/m);
    
    cout << mi << &#39; &#39; << ma << &#39;\n&#39;;
  }
}
