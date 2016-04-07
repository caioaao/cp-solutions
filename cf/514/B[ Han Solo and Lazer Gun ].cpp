#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

struct point{
  int x, y;
  point(){}
  point(int x, int y):
    x(x), y(y){ }
};

inline int cross(const point & a, const point & b){
  return a.x * b.y - a.y * b.x;
}


vector<point> lines;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  point ref;
  int N;
  while(cin >> N >> ref.x >> ref.y){
    lines.clear();
    point pt;
    for(int i = 0; i < N; i++){
      cin >> pt.x >> pt.y;
      pt.x -= ref.x;
      pt.y -= ref.y;
      size_t j = 0;
      for(;j < lines.sz(); j++)
	if(!cross(lines[j],pt)) break;
      if(j == lines.sz()) lines.pb(pt);
    }
    cout << lines.sz() << &#39;\n&#39;;
  }
}
