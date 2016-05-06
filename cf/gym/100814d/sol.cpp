#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))
#define msv(x,v) memset(&(x), (v), sizeof(x))

#define _DONT_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

using namespace std;

typedef long long L;
typedef unsigned long long UL;
typedef double D;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

const int MAXN = 1010010;

const char INF = 0x7f; // works with memset

int n;
PL melted[MAXN];
int amt_leaves;
VVPL adj_lst;

inline bool is_leaf(int u) {return adj_lst[u].sz() == 0;}

void melt(int u, L t) {
    if(is_leaf(u)) {
        ++amt_leaves;
        melted[u].ff = t;
        melted[u].ss = u;
    }
    else {
        const VPL& chld = adj_lst[u];

        L smaller_t = chld[0].ss;

        for(size_t i = 1; i < chld.sz(); ++i) {
            smaller_t = min(smaller_t, chld[i].ss);
        }

        for(size_t i = 0; i < chld.sz(); ++i) {
            melt(chld[i].ff, t + smaller_t + 2LL*(chld[i].ss - smaller_t));
        }
    }
}

int binary_search(L t) {
    int lo = 0, hi = n - 1, ans = 0;
    for(int i = 0; i < 40 && hi >= lo; ++i) {
        int md = (lo + hi) / 2;
        if(melted[md].ff <= t && is_leaf(melted[md].ss)){
            lo = md + 1;
            ans = max(ans, md);
        }
        else hi = md - 1;
    }

    if(melted[ans].ff <= t) ++ans;
    LOG("t=" << t << ";lo=" << lo << ";hi=" << hi << ";ans=" << ans << endl);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ms(melted, INF);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        adj_lst.assign(n, VPL());
        for(int i = 1; i < n; ++i) {
            int p, c;
            cin >> p >> c;
            adj_lst[--p].pb(PL(i, c));
        }

        // just reseting 'melted' array
        for(int i = 0; i < n; ++i) {
            msv(melted[i].ff, INF);
            melted[i].ss = 0;
        }

        amt_leaves = 0;
        melt(0, 0);
        sort(melted, melted + n);

        int q;
        cin >> q;
        while(q--) {
            L time;
            cin >> time;
            PL *lb = lower_bound(melted, melted + amt_leaves, PL(time, n+1));

            int ans = distance(melted, lb);
            if(lb->ff <= time) ++ans;
            cout << ans << '\n';
        }
    }
}
