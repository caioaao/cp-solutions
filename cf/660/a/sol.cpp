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
#define MAXN 1010
#define MAXV 1000000000LL
L vs[MAXN];

L gcd(L a, L b) { return (b == 0 ? a : gcd(b, a % b)); }

void solve(int n)
{
    int cnt = 0;
    for(int i = 0; i < n -1; ++i)
    {
        if(gcd(vs[i], vs[i + 1]) > 1)
            ++cnt;
    }

    cout << cnt << '\n';

    for(int i = 0; i < n - 1; ++i)
    {
        cout << vs[i] << ' ';
        if(gcd(vs[i], vs[i + 1]) > 1) cout << 1 << ' ';
    }

    cout << vs[n-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i) cin >> vs[i];
        solve(n);
    }
}
