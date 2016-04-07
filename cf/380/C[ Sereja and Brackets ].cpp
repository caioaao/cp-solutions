#include <bits/stdc++.h>

#define CL(x) (x)*2
#define CR(x) (x)*2+1

#define MAX_N 1000001

using namespace std;
typedef vector<int> vi;
int m, st[20*MAX_N];

void update(int node, int L, int R, int x){
  if(x < L || x > R) return;
  
  if(L == R){
    st[node]++;
    return;
  }
  
  update(CL(node), L, (L+R)/2, x);
  update(CR(node), (L+R)/2+1, R, x);
  
  st[node] = st[CL(node)] + st[CR(node)];
}

int query(int node, int L, int R, int qL, int qR){
  if(R < qL || L > qR) return 0;
  
  if(L >= qL && R <= qR){
      return st[node];
  }
  
  return query(CL(node), L, (L+R)/2, qL, qR) + query(CR(node), (L+R)/2+1, R, qL, qR);
}

vector<vi> qs;
vi ans, op;
vector<int> beg;

int main(){
  ios_base::sync_with_stdio(false);
  string linha;
  //~ while(getline(cin,linha)){
    getline(cin, linha);
    //~ cout << linha << endl;
    memset(st, 0, sizeof st);
    cin >> m;
    ans.assign(m, 0);
    beg.assign(m, 0);
    qs.assign(linha.size(), vi());
    int a, b;
    for(int i = 0; i < m; i++){
      cin >> a >> b;
      beg[i] = a-1;
      qs[b-1].push_back(i);
    }
    op.clear();
    int q;
    for(int i = 0; i < (int)linha.size(); i++){
      if(linha[i] == &#39;)&#39;){
        if(op.size() > 0){
          update(1,0,(int)linha.size()-1, op.back());
          op.pop_back();
        }
      }
      for(int j = 0; j < (int)qs[i].size(); j++){
        q = qs[i][j];
        ans[q] = query(1, 0, (int)linha.size()-1, beg[q], i);
      }
      
      if(linha[i] == &#39;(&#39;) op.push_back(i);
    }
    
    for(int i = 0; i < m; i++) cout << ans[i]*2 << &#39;\n&#39;;
  //~ }
}
