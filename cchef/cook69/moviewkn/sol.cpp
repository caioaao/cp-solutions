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
#define MAXN 110
L l[MAXN], r[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        VL ans(3, 0);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> l[i];
        for(int i = 0; i < n; ++i) cin >> r[i];
        for(int i = -1; i >= -n; --i){
            VL curr(3,i);
            curr[0] = l[-(i + 1)] * r[-(i + 1)];
            curr[1] = r[-(i + 1)];
            ans = max(ans, curr);
        }
        cout << (-ans[2]) << '\n';
    }
}
