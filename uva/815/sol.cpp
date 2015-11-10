#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))

#define MAXN 40
#define EPS  1e-8

#define _NO_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

using namespace std;

typedef double D;
typedef long long L;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

int n, m;
L alt[MAXN][MAXN];
L v_agua;

D vol(D l) {
    LOG(l << '\n');
    D v = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(alt[i][j] < l - EPS) {
                v += (l - alt[i][j]) * 100;
            }
        }
    }
    LOG(v << '\n');
    return v;
}

D pct(D l) {
    L cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(alt[i][j] < l) ++cnt;
        }
    }

    return (100. * cnt) / (n * m);
}

void solve() {
    L offs = alt[0][0];
    D lo = 0;
    D hi = alt[0][0];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            offs = min(offs, alt[i][j]);
            hi = max(hi, (double)alt[i][j]);
        }

    hi += v_agua;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            alt[i][j] -= offs;

    for(int cnt = 0; cnt < 100; ++cnt) {
        D mi = (hi + lo) / 2;

        if(vol(mi) > v_agua + EPS) {
            hi = mi;
        }
        else {
            lo = mi;
        }
    }

    cout << "Water level is "
         << fixed << setprecision(2) << (lo + offs) << " meters.\n";

    cout << fixed << setprecision(2) << pct(lo)
         << " percent of the region is under water.\n\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 1;
    while(cin >> n >> m && n != 0) {

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> alt[i][j];

        cin >> v_agua;
        cout << "Region " << cnt++ << '\n';
        solve();
    }
}
