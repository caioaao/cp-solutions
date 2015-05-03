#include <bits/stdc++.h>

#define MAX_M 100000
#define MAX_S 50000
#define MAX_N 20000

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

vsi queries;
int e[MAX_M], a[MAX_M], b[MAX_M], w[MAX_M], anss[MAX_S];

inline bool cmp_e(int lhs, int rhs){return w[lhs] > w[rhs];}

int p[MAX_N];

int n, m, s;


void UF(){for(int i = 0; i < n; i++) p[i] = i;}
int findSet(int x){ return (p[x] = p[x] == x ? x : findSet(p[x])); }
int isSameSet(int x, int y){ return findSet(x) == findSet(y); }
void unionSet(int x, int y, int w){
  // presume-se que sao diferentes aqui
  // x eh o peso da aresta
  findSet(x); findSet(y);
  if(queries[p[y]].size() > queries[p[x]].size()) swap(x,y);
  for(si::const_iterator it = queries[p[y]].begin(); it != queries[p[y]].end(); ++it){
    if(queries[p[x]].count(*it)){
      anss[*it] = w;
      queries[p[x]].erase(*it);
    }
    else{
      queries[p[x]].insert(*it);
    }
  }
  queries[p[y]].clear();
  p[p[y]] = p[x];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(cin >> n >> m >> s){
    queries.assign(n,si());
    for(int i = 0; i < m; i++){
      e[i] = i;
      cin >> a[i] >> b[i] >> w[i];
      a[i]--; b[i]--;
    }
    sort(e, e+m, cmp_e);
    int x,y;
    for(int i = 0; i < s; i++){
      cin >> x >> y;
      x--;y--;
      queries[x].insert(i);
      queries[y].insert(i);
    }
    int sets = n;
    UF();
    for(int i = 0; i < m && sets > 1; i++){
      if(!isSameSet(a[e[i]],b[e[i]])){
        sets--;
        unionSet(a[e[i]], b[e[i]], w[e[i]]);
      }
    }
    for(int i = 0; i < s; i++) cout << anss[i] << '\n';
  }
}
