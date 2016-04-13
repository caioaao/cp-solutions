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

#define MAXN 3010100

int v[MAXN];

void solve(int n, int k) {
    int zeros = 0;
    int ones = 0;
    int rb = -1, rf = -1, rl = 0;
    int beg = -1;
    for(int i = 0; i < n; ++i) {
        if(v[i]) ++ones;
        else ++zeros;
        while(zeros > k) {
            ++beg;
            if(v[beg]) --ones;
            else --zeros;
        }
        if(zeros + ones >= rl) {
            rb = beg; rf = i; rl = zeros + ones;
        }
    }

    for(int i = rb + 1; i <= rf; ++i) {
        v[i] = 1;
    }
    cout << rl << '\n';
    for(int i = 0; i < n; ++i) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    while(cin >> n >> k) {
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        solve(n, k);
    }
}
