#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 110
#define MAXM 110000

#define INF (MAXN * 4110)

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

L n, m;
L costs[MAXN];
L vals[MAXN];

L memo[MAXN][MAXM];

L solve() {
    if(n == 0 || m == 0) return 0;
    memo[n][0] = 0;
    for(int i = 1; i <= m + 200; ++i){
        memo[n][i] = -INF;
    }

    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < costs[i]; ++j) memo[i][j] = memo[i + 1][j];
        for(int j = costs[i]; j <= m + 200; ++j) {
            memo[i][j] = max(memo[i + 1][j],
                             memo[i + 1][j - costs[i]] + vals[i]);
        }
    }

    L ans = 0;
    for(int i = 0; i <=m; ++i) {
        ans = max(ans, memo[0][i]);
    }
    for(int i = max(m, 2000LL) + 1; i <= m + 200; ++i) {
        ans = max(ans, memo[0][i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while(cin >> m >> n) {
        for(int i = 0; i < n; ++i) {
            cin >> costs[i] >> vals[i];
        }
        cout << solve() << '\n';
    }
}
