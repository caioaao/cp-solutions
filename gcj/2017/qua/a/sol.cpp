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

string s;
int k, n;

inline void flip(int i) {
    if(s[i] == '-') s[i] = '+';
    else s[i] = '-';
}

int solve(int i) {
    if(i == n) return 0;
    if(s[i] == '-'){
        if(i + k <= n) {
            for(int j = i; j < i + k; ++j) flip(j);
            int aux = solve(i + 1);
            if(aux == -1) return -1;
            return aux + 1;
        }
        else {
            return -1;
        }
    }
    else {
        return solve(i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        cin >> s >> k;
        n = s.sz();
        int ans = solve(0);
        if(ans == -1) cout << "IMPOSSIBLE";
        else cout << ans;
        cout << '\n';
    }
}
