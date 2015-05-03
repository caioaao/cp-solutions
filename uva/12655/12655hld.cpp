#include <bits/stdc++.h>

#define pb push_back
#define sz size
#define INF 1e9
#define MAXN 200001
#define cl(x) ((x)<<1)
#define cr(x) ((x)<<1)+1

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

class LCA{
private:int L[2*MAXN], E[2*MAXN], H[MAXN], idx, st[4*MAXN], n;

  void dfs(int cur, int depth, vvi & children) {
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;
    for (int i = 0; i < (int)children[cur].size(); i++) {
      dfs(children[cur][i], depth+1, children);
      E[idx] = cur;
      L[idx++] = depth;
    }
  }
  void build_tree(int x, int l, int r, vvi & children){
    if(l == r)
      st[x] = l;
    else{
      build_tree(cl(x), l, (l+r)/2, children);
      build_tree(cr(x), (l+r)/2+1,r, children);
      if(L[st[cl(x)]] < L[st[cr(x)]]) st[x] = st[cl(x)];
      else st[x] = st[cr(x)];
    }
  }
  
  int query_tree(int x, int l, int r, int i, int j){
    if(i > r || j < l) return -1;
    if(l >= i && r <= j) return st[x];
    
    int vl = query_tree(cl(x), l, (l+r)/2, i, j),
      vr = query_tree(cr(x), (l+r)/2+1, r, i, j);
    
    if(vl == -1) return vr;
    if(vr == -1) return vl;
    if(L[vl] < L[vr]) return vl;
    return vr;
  }
public:
  void build(vvi & children){
    idx = 0;
    n = children.sz()*2 - 1;
    memset(H, -1, sizeof H);
    dfs(0, 0, children);
    build_tree(1,0, n, children);
  }
  int query(int u, int v){
    if(H[v] < H[u])swap(u,v);
    return E[query_tree(1,0,n,H[u],H[v])];
  }
};

class HLD{
private:
  LCA lca;
  int chainNo, chainPtr, n;
  int chainHead[MAXN], chainPos[MAXN], chainInd[MAXN];
  int arrBase[MAXN], tree_sz[MAXN], st[4*MAXN], parent[MAXN];

  void build_tree(int x, int l, int r){
    if(l == r) st[x] = arrBase[l];
    else{
      build_tree(cl(x), l, (l+r)/2);
      build_tree(cr(x), (l+r)/2+1, r);
      st[x] = min(st[cl(x)], st[cr(x)]);
    }
  }

  int query_tree(int x, int l, int r, int i, int j){
    if(j < l || i > r) return INF;
    if(l >= i && r <= j) return st[x];
    
    return min(query_tree(cl(x), l, (l+r)/2, i, j),
               query_tree(cr(x), (l+r)/2+1,r, i, j));
  }

  int query_up(int u, int v){
    if(u == v) return INF;
    
    int uchain, vchain = chainInd[v], ans = INF;
    
    while(1){
      uchain = chainInd[u];
      if(uchain == vchain){
        if(u == v) break;
        ans = min(ans,query_tree(1,0,n-1, chainPos[v]+1,chainPos[u]));
        break;
      }
      ans = min(ans,query_tree(1,0,n-1, chainPos[chainHead[uchain]], chainPos[u]));
      u = parent[chainHead[uchain]];
    }
    return ans;
  }

  int dfscnt(int u, vvi & children){
    int v;
    tree_sz[u] = 1;
    
    for(int i = 0; i < (int)children[u].sz(); i++){
      v = children[u][i];
      parent[v] = u;
      tree_sz[u] += dfscnt(v,children);
    }
    
    return tree_sz[u];
  }
  
  void hld(int u, int cst, vvi & children, vvi & costs){
    arrBase[chainPtr] = cst;
    if(chainHead[chainNo] == -1) chainHead[chainNo] = u;
    chainInd[u] = chainNo; chainPos[u] = chainPtr++;
    
    int ind = n, nc, v;
    for(int i = 0; i < (int) children[u].sz(); i++){
      v = children[u][i];
      if(tree_sz[v] > tree_sz[ind]){
        ind = v;
        nc = costs[u][i];
      }
    }
    if(ind == n) return;
    hld(ind, nc, children, costs);
    
    for(int i = 0; i < (int) children[u].sz(); i++){
      v = children[u][i];
      if(v != ind){
        chainNo++;
        hld(v, costs[u][i], children, costs);
      }
    }
  }

public:
  HLD(){
    lca = LCA();
  }
  void build(vvi & children, vvi & costs){
    memset(tree_sz, -1, sizeof tree_sz);
    n = children.size();
    dfscnt(0,children);
    
    chainNo = 0;
    memset(chainHead, -1, sizeof chainHead);
    chainPtr = 0;
    hld(0, INF, children, costs);
    
    lca.build(children);
    build_tree(1,0,n-1);
  }
  
  int query(int u, int v){
    int l = lca.query(u,v);
    return min(query_up(u,l), query_up(v,l));
  }
};


  

struct edge{
  int u,v, w;
  bool operator< (const edge & r) const{
    return w < r.w;
  }
  bool operator> (const edge & r) const{
    return w > r.w;
  }
};


int n,m,s;

class UF{
  private:
    vi p;
  public:
    void build(){
      p.assign(n,0);
      for(int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int u){ return p[u] = u == p[u] ? u : findSet(p[u]);}
    bool isSameSet(int u, int v){ return findSet(u) == findSet(v);}
    void unionSet(int u, int v){
      p[findSet(u)] = findSet(v);
    }
};

UF uf = UF();

vector<edge> E;

vvi adj, costs, children, costsc;
vi parent;


void dfsRoot(int u, int p){
  int v, w;
  for(int i = 0; i < (int)adj[u].size(); i++){
    v = adj[u][i];
    if(v != p){
      w = costs[u][i];
      children[u].pb(v);
      costsc[u].pb(w);
      dfsRoot(v,u);
    }
  }
}

HLD hld = HLD();
void populate(){
  sort(E.begin(),E.end(), greater<edge>());
  uf.build();
  adj.assign(n,vi());
  costs.assign(n,vi());
  for(int i = 0; i < m; i++)if(!uf.isSameSet(E[i].u,E[i].v)){
    uf.unionSet(E[i].u,E[i].v);
    adj[E[i].u].pb(E[i].v); costs[E[i].u].pb(E[i].w);
    adj[E[i].v].pb(E[i].u); costs[E[i].v].pb(E[i].w);
  }
  parent.assign(n+1,0);
  children.assign(n,vi());
  costsc.assign(n,vi());
  dfsRoot(0,n);
  hld.build(children, costsc);
  
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  while(cin >> n >> m >> s){
    E.assign(m, edge());
    
    for(int i = 0; i < m; i++){
      cin >> E[i].u >> E[i].v >> E[i].w;
      E[i].u--; E[i].v--;
    }

    populate();
    int u, v;
    while(s--){
      cin >> u >> v;
      --u,--v;
      //cout << u << ' ' << v << '=';
      cout << hld.query(u,v) << '\n';
    }
  }
}
