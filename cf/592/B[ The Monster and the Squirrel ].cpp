#include <bits/stdc++.h>

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
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    L n;
    while(cin >> n) {
        cout << (1 + 3 *(n - 3) + (n - 3) * (n - 4)) << &#39;\n&#39;;
    }
}
