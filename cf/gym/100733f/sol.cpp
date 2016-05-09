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
// #include <functional>

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


class TimeToIndex {
private:
    VL sorted_d_;
public:
    TimeToIndex(const VL& d) {
        sorted_d_ = d;
        sort(sorted_d_.begin(), sorted_d_.end());
    }
    int operator()(L di) {
        return distance(sorted_d_.begin(), lower_bound(sorted_d_.begin(), sorted_d_.end(), di));
    }
};

class SegTree {
private:
    VL st_;
    int n_;

    inline int cl(int x) {return x * 2;}
    inline int cr(int x) {return (x * 2) + 1;}

    L query_(int x, int i, int j, int a, int b) {
        if(i > b || j < a) return 0;
        if(i >= a && j <= b) return st_[x];
        return max(query_(cl(x), i, (i + j) / 2, a, b),
                   query_(cr(x), (i + j) / 2 + 1, j, a, b));
    }

    void update_(int x, int i, int j, int k, L v) {
        if(k > j || k < i) return;
        if(i == j) st_[x] = max(v, st_[x]);
        else {
            st_[x] = max(st_[x], v);
            update_(cl(x), i, (i + j) / 2, k, v);
            update_(cr(x), (i + j) / 2 + 1, j, k, v);
        }
    }

public:
    SegTree(int n) {
        n_ = n;
        st_.assign(n * 8, 0);
    }

    L query(int a, int b) {return query_(1, 0, n_, a, b); }
    void update(int k, L v) { update_(1, 0, n_, k, v); }
};

int solve(const VL& d, const VL& v, const VL& t) {
    TimeToIndex time_parser(d);
    SegTree dp(d.sz()); // dp[i] = biggest seq ending in day i, rmq(i, j) -> biggest seq ending between days i and j

    for(size_t i = 0; i < d.sz(); ++i) {
        dp.update(time_parser(d[i]), v[i] + dp.query(time_parser(d[i] - t[i]), time_parser(d[i])));
    }

    return dp.query(0, d.sz());
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    VL d, v, t;
    int n;
    while(cin >> n) {
        d.assign(n, 0);
        v.assign(n, 0);
        t.assign(n, 0);

        for(int i = 0; i < n; ++i) {
            cin >> d[i] >> v[i] >> t[i];
        }
        cout << solve(d, v, t) << '\n';
    }
}

