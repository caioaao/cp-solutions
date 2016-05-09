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

#define N_USE_LOG
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
const int MAXD = 22;
int n;
L p10(int i0) {
    L p = 1;
    for(int i = i0 + 1; i < n; ++i) p *= 10L;
    return p;
}

L delta(int i, L a, L b) {
    return p10(i) * (a - b);
}
L dp(int i, int cmp);

string s1, s2;
L memo[MAXD][3];
PL best[MAXD][3];
void dp_c(int i) {
    // min c, max j
    if(s1[i] != '?' && s2[i] != '?') {
        memo[i][1] = dp(i+1, 1) + delta(i, s1[i] - '0', s2[i] - '0');
        best[i][1] = PL(s1[i] - '0', s2[i] - '0');
    }
    else if(s1[i] == '?' && s2[i] != '?') {
        memo[i][1] = dp(i+1, 1) + delta(i, 0, s2[i] - '0');
        best[i][1] = PL(0, s2[i] - '0');
    }
    else if(s1[i] != '?' && s2[i] == '?') {
        memo[i][1] = dp(i+1, 1) + delta(i, s1[i] - '0', 9);
        best[i][1] = PL(s1[i] - '0', 9);
    }
    else if(s1[i] == '?' && s2[i] == '?') {
        memo[i][1] = dp(i+1, 1) + delta(i, 0, 9);
        best[i][1] = PL(0, 9);
    }
}
void dp_j(int i) {
    // min j, max c
    if(s1[i] != '?' && s2[i] != '?') {
        memo[i][2] = dp(i+1, 2) + delta(i, s2[i] - '0', s1[i] - '0');
        best[i][2] = PL(s1[i] - '0', s2[i] - '0');
    }
    else if(s1[i] == '?' && s2[i] != '?') {
        memo[i][2] = dp(i+1, 2) + delta(i, s2[i] - '0', 9);
        best[i][2] = PL(9, s2[i] - '0');
    }
    else if(s1[i] != '?' && s2[i] == '?') {
        memo[i][2] = dp(i+1, 2) + delta(i, 0, s1[i] - '0');
        best[i][2] = PL(s1[i] - '0', 0);
    }
    else if(s1[i] == '?' && s2[i] == '?') {
        memo[i][2] = dp(i+1, 2) + delta(i, 0, 9);
        best[i][2] = PL(9, 0);
    }
}
void dp_tie(int i) {
    // min delta
    if(s1[i] != '?' && s2[i] != '?') {
        L d = abs(delta(i, s1[i] - '0', s2[i] - '0'));
        int c;
        if(s1[i] > s2[i]) c = 1;
        else if(s1[i] < s2[i]) c = 2;
        else c = 0;
        memo[i][0] = dp(i+1, c) + d;
        best[i][0] = PL(s1[i] - '0', s2[i] - '0');
    }
    else if(s1[i] != '?' && s2[i] == '?'){
        memo[i][0] = dp(i+1, (s1[i] == '0' ? 0 : 1)) + delta(i, s1[i] - '0', 0);
        best[i][0] = PL(s1[i] - '0', 0);
        L aux;
        int c;
        for(int k = 1; k < 10; ++k) {
            if(s1[i] > k + '0') c = 1;
            else if(s1[i] < k + '0') c = 2;
            else c = 0;
            if(c == 1) aux = delta(i, s1[i] - '0', k);
            else if(c == 2) aux = delta(i, k, s1[i] - '0');
            else aux = 0;
            aux += dp(i + 1, c);
            if(aux < memo[i][0]) {
                memo[i][0] = aux;
                best[i][0].ss = k;
            }
        }
    }
    else if(s1[i] == '?' && s2[i] != '?'){
        memo[i][0] = dp(i+1, (s2[i] == '0'? 0 : 2)) + delta(i, s2[i] - '0', 0);
        best[i][0] = PL(0, s2[i] - '0');
        L aux;
        int c;
        for(int k = 1; k < 10; ++k) {
            if(s2[i] > k + '0') c = 2;
            else if(s2[i] < k + '0') c = 1;
            else c = 0;
            if(c == 2) aux = delta(i, s2[i] - '0', k);
            else if(c == 1) aux = delta(i, k, s2[i] - '0');
            else aux = 0;
            aux += dp(i + 1, c);
            if(aux < memo[i][0]) {
                memo[i][0] = aux;
                best[i][0].ff = k;
            }
        }
    }
    else{
        memo[i][0] = dp(i + 1, 0);
        best[i][0] = PL(0, 0);
        int c;
        L aux;
        for(int k = 0; k < 2; ++k) {
            for(int j = 0; j < 2; ++j) {
                if(k > j) c = 1;
                else if(k < j) c = 2;
                else c = 0;

                LOG("k: " << k << ", j: " << j << ", c:  " << c << endl);
                aux = dp(i + 1, c) + abs(delta(i, k, j));
                if(aux < memo[i][0]) {
                    memo[i][0] = aux;
                    best[i][0] = PL(k, j);
                }
            }
        }
    }

}

L dp(int i, int cmp) {
    LOG("i: " << i << ", cmp = " << cmp << endl);
    if(i == n) { return 0; }
    if(memo[i][cmp] == -1) {
        if(cmp == 0) dp_tie(i);
        else if(cmp == 1) dp_c(i);
        else if(cmp == 2) dp_j(i);
    }
    LOG("memo[" << i << "][" << cmp << "] = " <<  memo[i][cmp] << endl);
    LOG("bst[" << i << "][" << cmp << "] = (" <<  best[i][cmp].ff << ", "  <<  best[i][cmp].ss << ')' << endl);
    return memo[i][cmp];
}

void mk_sol(int i, int cmp) {
    if(i < n) {
        s1[i] = best[i][cmp].ff + '0';
        s2[i] = best[i][cmp].ss + '0';
        int c = cmp;
        if(c == 0) {
            if(s1[i] > s2[i]) c = 1;
            else if(s1[i] < s2[i]) c = 2;
        }
        mk_sol(i + 1, c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        memset(memo, -1, sizeof memo);
        cin >> s1 >> s2;
        n = s1.length();
        L d = dp(0, 0);
        LOG("delta = " << d << endl);

        mk_sol(0, 0);
        cout << s1 << ' ' << s2;
        cout << '\n';
    }
}
