#include <bits/stdc++.h>

using namespace std;

struct point{
  int x,y;
  point(){;}
  point(int _x, int _y){
    x = _x;
    y = _y;
  }
};

vector<point> pts;
int main(){
  int n,m,k;
  cin >> n >> m >> k;
  
  int amt = (n*m)/k;
  int amt1 = amt + (n*m)%k;
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      pts.push_back(point(i, (i%2 == 0 ? m-j+1 : j)));
    }
  }
  cout << amt1;
  int i = 0, q;
  for(; i < amt1; i++)
    cout << &#39; &#39; << pts[i].x << &#39; &#39; << pts[i].y;
  cout << &#39;\n&#39;;
  
  for(int j = 0; j < (n*m - amt1)/amt; j++){
    cout << amt;
    for(q = i; q < i+amt; q++) cout << &#39; &#39; << pts[q].x << &#39; &#39; << pts[q].y;
    i = q;
    cout << &#39;\n&#39;;
  }
}
