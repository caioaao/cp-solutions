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

#define _NO_USE_LOG
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

L lca(L a, L b) {
    while(a != b) {
        if(a < b) swap(a,b);
        a /= 2;
    }
    return a;
}

L depth(L u, L p) {
    L i = 0;
    while(u != p) {
        u /= 2;
        ++i;
    }
    return i;
}

L getw(L u, L v, L p) {
    if(u > v) swap(u,v);
    L du = depth(u, p);
    L dv = depth(v, p);
    while(dv > du){
        v /= 2;
        --dv;
    }
    if(u > v) swap(u, v);

    return v - u + 1;
}

inline VL ptransfu(L u, L p) {
    VL ans;
    while(u != p) {
        ans.pb(u % 2 ? 1 : 0);
        u /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


inline L apply_trans(const VL &t, L u, L n) {
    for(VL::const_iterator it = t.begin(); it != t.end(); ++it) {
        u = u*2 + *it;
        if(u > n) return -1;
    }
    return (u <= n ? u : -1);
}

inline L p2(L p) { return (1LL << p); }

inline L poss(L n, L p, const VL& transf) {
    return (-1 != apply_trans(transf, p, n));
}

inline L bs(L n, L l, const VL& transf) {
    L lo = p2(l);
    L hi = lo * 2 - 1;
    L mi;
    for(int i = 0; i < 30; ++i) {
        mi = (lo + hi) / 2;
        if(poss(n, mi, transf)) lo = mi;
        else hi = mi - 1;
    }
    LOG("bs(l=" << l << "): lo:" << lo << ", hi:" << hi
        << ", lo_poss:" << poss(n, lo, transf)
        << ", hi_poss:" << poss(n, hi, transf) << endl);
    if(poss(n, hi, transf)) return hi;
    else return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    L n, u, v, p;
    VL transf;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cin >> n >> u >> v;
        if(u > v) swap(u, v);
        p = lca(u, v); // logn
        transf = ptransfu(max(u,v), p); //logn
        LOG("u:" << u << ",v:"<< v << ",p:" << p << '\n');
        LOG("ptransfu:" << apply_trans(transf, p, n) << endl);

        UL ans = 0;
        for(L l = 0; p2(l) <= n; ++l) {
            if(poss(n, p2(l), transf)) {
                ans += bs(n, l, transf) - p2(l) + 1;
            }
        }
        cout << ans << '\n';
    }
}
