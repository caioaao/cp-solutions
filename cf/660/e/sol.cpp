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

const L MOD = L(1000 * 1000 * 1000) + 7;

L solve(L n, L m) {
    L sl = 1;
    L p = 1;

    for(int i = 0; i < n; ++i) {
        sl = (sl * 2 * m - sl + p) % MOD;
        p = (p * m) % MOD;
    }
    // cout << "p:" << p << ',';
    // cout << "sl:" << sl << ',';
    return sl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    L n,m;
    while(cin >> n >> m) {
        cout << solve(n, m) << '\n';
    }
}
