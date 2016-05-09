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
#define cntb(x) __builtin_popcount(x)

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

void prl(L x, int n) {
    for(int i = 0; i < n; ++i) {
        cout << !!(x & (1LL << i));
    }
}

void prl_inv(L x, int n) {
    for(int i = n - 1; i >= 0; --i) {
        cout << !!(x & (1LL << i));
    }
}

L inv_b(L x, int n) {
    L ans = 0;
    for(int i = 0; i < n; ++i) {
        ans |= (!!(x & (1LL << (n - i - 1))) << i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        int b;
        L m;
        cin >> b >> m;

        if(m > (1LL << (b - 2)) || cntb(m) > b - 1) cout << "IMPOSSIBLE";
        else {
            cout << "POSSIBLE\n";
            prl_inv(min(m << 1, (1LL << (b - 1))  - 1), b);
            for(int i = 2; i < b; ++i) {
                cout << '\n';
                prl_inv((1LL << (b - i)) - 1, b);
            }
            cout << '\n';
            prl_inv(0, b);
        }


        cout << '\n';
    }
}
