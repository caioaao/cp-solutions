#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 200

#define INF 1001000

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii adj;
vvi adj2;
vi energy;
vi dist;
int n;

bool mp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n) {
        if(n == -1) return 0;

        adj2.assign(n, vi());
        energy.assign(n, 0);
        int k;
        memset(mp, 0, sizeof(mp));

        for(int i = 0; i < n; ++i) {
            cin >> energy[i] >> k;
            adj2[i].assign(k, 0);

            for(int j = 0; j < k; ++j) {
                cin >> adj2[i][j];
                --adj2[i][j];
                mp[i][adj2[i][j]] = 1;
            }
        }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    mp[i][j] |= mp[i][k] & mp[k][j];

        adj.assign(n, vii());
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < (int)adj2[i].sz(); ++j) {
                adj[i].pb(ii(adj2[i][j], -energy[adj2[i][j]]));
            }
        }

        dist.assign(n, INF);
        dist[0] = -100;
        for(int i = 0; i < n - 1; ++i)
            for(int u = 0; u < n; ++u)
                for(int j = 0; j < (int) adj[u].sz(); ++j) {
                    ii v = adj[u][j];
                    if(dist[u] + v.second < 0) {
                        dist[v.first] = min(dist[v.first], dist[u] + v.second);
                    }
                }

        if(dist[n - 1]  < 0) cout << "winnable\n";
        else {
            bool hasNeg = false;
            for(int u = 0; u < n; ++u) {
                if(mp[u][n - 1]) {
                    for(int j = 0; j < (int) adj[u].sz(); ++j) {
                        ii v = adj[u][j];
                        if(dist[u] + v.second < 0 && dist[v.first] > dist[u] + v.second) {
                            hasNeg = true;
                        }
                    }
                }
            }
            if(hasNeg) cout << "winnable\n";
            else cout << "hopeless\n";
        }
    }
}
