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

const int MAXN = 20;
int vs[MAXN];
int n;

int visited[MAXN][11][2];
int best[MAXN][11][2];

int dp(int i, int last, bool sm){
    if(i == n) return 1;
    if(visited[i][last][sm]) return 0;
    visited[i][last][sm] = 1;
    if(sm) {
        for(int curr = 9; curr >= last; --curr) {
            if(dp(i + 1, curr, sm)) {
                best[i][last][sm] = curr;
                return 1;
            }
        }
        return 0;
    }
    else if(vs[i] >= last && dp(i + 1, vs[i], 0)) {
        best[i][last][sm] = vs[i];
        return 1;
    }
    else {
        for(int curr = vs[i] - 1; curr >= last; --curr) {
            if(dp(i + 1, curr, 1)) {
                best[i][last][sm] = curr;
                return 1;
            }
        }
        return 0;

    }
}

L ans(int i, int last, bool sm, L curr) {
    if(i == n) return curr;
    return ans(i + 1, best[i][last][sm], sm || best[i][last][sm] < vs[i],
               best[i][last][sm] + curr * 10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        cin >> s;
        n = s.sz();
        for(int i = 0; i < n; ++i) vs[i] = s[i] - '0';
        ms(visited, 0);
        dp(0, 0, 0);
        cout << ans(0, 0, 0, 0);
        cout << '\n';
    }
}
