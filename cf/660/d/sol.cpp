#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>

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

#define MAXN 2010

int x[MAXN];
int y[MAXN];
map<PL,L> cs;

L solve(int n) {
    cs.clear();
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int cx = (x[i] + x[j]);
            int cy = (y[i] + y[j]);
            ++cs[PL(cx, cy)];
        }
    }
    L ans = 0;
    for(map<PL,L>::const_iterator it = cs.begin(); it != cs.end(); ++it) {
        ans += (it->ss * (it->ss - 1))/2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        cout << solve(n);
    }
}
