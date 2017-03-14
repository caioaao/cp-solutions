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

const int MAXN = 100000;

L solve(L *v1, L *v2) {
    if(*v1 == -1) return 0;
    return *v1 + solve(v2 + 1, v1 + 1);
}

L v1[MAXN], v2[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {cin >> v1[i];}
        for(int i = 0; i < n; ++i) {cin >> v2[i];}
        v1[n] = v2[n] = -1;

        cout << min(solve(v1, v2), solve(v2, v1)) << '\n';
    }
}
