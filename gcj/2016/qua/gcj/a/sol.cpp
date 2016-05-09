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

const int ALL_SEEN = (1 << 10) - 1;

int which(UL x) {
    int seen = 0;
    while(x) {
        seen |= (1 << (x%10));
        x /= 10;
    }

    return seen;
}

UL solve(UL n) {
    UL s = n;
    int seen = 0;

    while(true) {
        seen |= which(s);

        if(seen == ALL_SEEN) break;
        s += n;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    UL n;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";

        cin >> n;

        if(n == 0) { cout << "INSOMNIA"; }
        else { cout << solve(n); }
        cout << '\n';
    }
}
