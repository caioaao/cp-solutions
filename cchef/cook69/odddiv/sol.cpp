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

#define MAXN 100100

inline L f(L n) {
    L s = 0;
    for(L i = 1; i*i <= n; ++i) {
        if(!(n % i)) {
            // cout << i << ' ' << n/i << '\n';
            if(i % 2) s += i;
            if(i != (n/i) && (n/i) % 2 ) s += n/i;
        }
    }
    return s;
}

L s[MAXN];

void prec() {
    s[0] = 0;

    for(int i = 1; i < MAXN; ++i) {
        s[i] = s[i - 1] + f(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << f(1) << '\n';;
    // cout << f(21) << '\n';;
    // cout << f(25) << '\n';;
    prec();
    int t, l, r;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cin >> l >> r;
        cout << (s[r] - s[l - 1]) << '\n';
    }
}
