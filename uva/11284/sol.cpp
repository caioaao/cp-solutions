#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))

#define _NO_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

#define MAXN 60
#define MAXP 12
#define EPS 1e-8
#define INF 1e8


using namespace std;

typedef long long L;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

int n, p, t;
int adj_mat[MAXN][MAXN];
int saves[MAXP];
int store_bm[MAXN];
int opera_store[MAXN];

L dist[MAXN][1 << MAXP];
int vis[MAXN][1 << MAXP];

L dp(int u, int bm_) {
    int bm = bm_ & ~store_bm[u];

    if(vis[u][bm] < t) {
        vis[u][bm] = t;
        if(bm == 0) dist[u][bm] = adj_mat[u][0];
        else {
            dist[u][bm] = INF;
            for(int i = 0; i < p; ++i) {
                if(bm & (1 << i)) {
                    dist[u][bm] = min(dist[u][bm],
                                      adj_mat[u][opera_store[i]] + dp(opera_store[i], bm));
                }
            }
        }
    }
    return dist[u][bm];
}

L saving[(1 << MAXP)];

inline void precsaving() {
    for(int bm = 0; bm < (1 << p); ++bm) {
        saving[bm] = 0;
        for(int i = 0; i < p; ++i) {
            saving[bm] += (!!(bm & (1 << i))) * saves[i];
        }
    }
}

void fw() {
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                adj_mat[i][j] = min(adj_mat[i][k] + adj_mat[k][j], adj_mat[i][j]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ms(vis, -1);
    int tsts;
    int m;
    cin >> tsts;
    for(t = 0; t < tsts; ++t) {
        cin >> n >> m;

        ++n;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                adj_mat[i][j] = INF;

        while(m--){
            int a, b;
            cin >> a >> b;
            double c_;
            cin >> c_;
            int c = 100*(c_ + EPS);
            if(adj_mat[a][b] > c) {
                adj_mat[a][b] = adj_mat[b][a] = c;
            }
        }

        fw();

        cin >> p;

        ms(store_bm, 0);

        for(int i = 0; i < p; ++i) {
            cin >> opera_store[i];
            store_bm[opera_store[i]] |= (1 << i);
            double c_;
            cin >> c_;
            saves[i] = 100 * (c_ + EPS);

        }

        precsaving();
        L bst = 0;
        for(int i = 0; i < (1 << p); ++i) {
            LOG(bitset<14>(i) << ':' << dist[0][i] << '\n');
            bst = max(bst, saving[i] - dp(0, i));
        }

        if(bst == 0) cout << "Don't leave the house\n";
        else cout << "Daniel can save $"
                  << fixed << setprecision(2) << (bst/100.) << '\n';

    }
}
