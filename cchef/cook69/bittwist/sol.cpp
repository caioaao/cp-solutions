#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iterator>

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

typedef unsigned long long L;
typedef unsigned long long UL;
typedef double D;
typedef pair<L,L> PL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;
const int MAXN = 100100;
L a[MAXN];
int lo[MAXN], hi[MAXN], de[MAXN];
int ctou[MAXN];

VVI adj;
VVI uperd;

int eul(int u, int d, int &cnt) {
    ctou[cnt] = u;
    lo[u] = hi[u] = cnt++;
    de[u] = d;
    int r = d;
    for(size_t i = 0; i < adj[u].sz(); ++i) {
        r = max(r,eul(adj[u][i], d+1, cnt));
        hi[u] = cnt;
    }

    return r;
}

void cat(int n) {
    for(int i = 0; i < n; ++i) {
        uperd[de[ctou[i]]].pb(i);
    }
}

inline L bitTwister(L x, L y){
    x ^= x >> 11;
    x ^= (x << 7) & 2636928640;
    x ^= (x << 15) & 4022730752;
    x ^= (x >> 18);
    return (1812433253 * (x ^ (x >> 30)) + y) & 4294967295;
}

map<VI, L> memo;
L calc(int d, VI::iterator li, int hi, VI::iterator fin) {
    LOG(*li << ' '  << hi << endl);
    VI s(3, d); s[1] = *li; s[2] = hi;
    if(!memo.count(s)) {
        L &ans = (memo[s] = a[ctou[*li]]);
        ++li;
        for(; li != fin && *li < hi; ++li) {
                ans = bitTwister(ans, a[ctou[*li]]);
        }
        return ans;
    }
    else return memo[s];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, q;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for(int i = 0; i < n; ++i) cin >> a[i];

        adj.assign(n, VI());

        for(int i = 1; i < n; ++i) {
            int pi;
            cin >> pi;
            adj[--pi].pb(i);
        }

        int cnt = 0;
        int h = eul(0, 0, cnt);

        uperd.assign(h+1, VI());
        cat(cnt);
        LOG("cnt: " << cnt << endl);

        int p, d, dr;
        memo.clear();

        while(q--) {
            cin >> p >> d;
            --p;
            dr = d + de[p];
            LOG("d to root: " << dr << endl);
            VI::iterator li = lower_bound(uperd[dr].begin(), uperd[dr].end(), lo[p]);

            LOG("l:" << ctou[*li] << endl);
            cout << calc(dr, li, hi[p], uperd[dr].end()) << '\n';
        }
    }
}

