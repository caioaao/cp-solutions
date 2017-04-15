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

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))

using namespace std;

typedef long long L;
typedef unsigned long long UL;
typedef double D;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

#define _NO_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

void solve(L n, L k) {
    LOG("solve(" << n << ',' << k << ')');
    L small, big;
    if(n & 1) {
        small = big = (n - 1) / 2;
    }
    else {
        small = (n - 1) / 2;
        big = small + 1;
    }
    if (k == 1) {
        cout << big << ' ' << small;
    }
    else if((--k) & 1) {
        solve(big, k / 2 + 1);
    }
    else {
        solve(small, k / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    L n, k;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        cin >> n >> k;
        solve(n, k);
        cout << '\n';
    }
}
