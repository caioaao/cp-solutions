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

bool ok(const VL& ps) {
    L soma = 0;
    for(size_t i = 0; i < ps.sz(); ++i) {
        if(ps[i] < 0) return false;
        soma += ps[i];
    }
    for(size_t i = 0; i < ps.sz(); ++i) {
        if(ps[i] >= L(soma/2) + 1) return false;
    }
    return true;
}

bool zerado(const VL& ps) {
    for(size_t i = 0; i < ps.sz(); ++i) {
        if(ps[i] > 0) return false;
    }
    return true;
}

string choose_one (const VL& ps) {
    VL ps_after;
    for(size_t i = 0; i < ps.sz(); ++i) {
        ps_after = ps;
        --ps_after[i];
        if(ok(ps_after)) {
            string ans = "a";
            ans[0] = i + 'A';
            return ans;
        }
    }
    return "";
}

string choose_two(const VL& ps) {
    VL ps_after;
    for(size_t i = 0; i < ps.sz(); ++i) {
        for(size_t j = i; j < ps.sz(); ++j) {
            ps_after = ps;
            --ps_after[i]; --ps_after[j];
            if(ok(ps_after)) {
                string ans = "aa";
                ans[0] = i + 'A';
                ans[1] = j + 'A';
                return ans;
            }
        }
    }
    return "";
}

void solve() {
    int n;

    cin >> n;
    VL ps(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> ps[i];
    }

    while(!zerado(ps)) {
        LOG(1 << endl);
        string s = choose_two(ps);
        LOG(2 << endl);
        if(s.length() == 0) s = choose_one(ps);
        LOG(3 << endl);
        cout << ' ' << s;
        for(size_t i = 0; i < s.length(); ++i) {
            --ps[s[i] - 'A'];
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":";
        solve();
        cout << '\n';
    }
}
