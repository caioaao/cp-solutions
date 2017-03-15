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

#define UL0 ((UL)0)
#define UL1 ((UL)1)

const int MAXN = 1000001;

UL sched[20000];

UL left_border(int start) {
    int beg_bit = start % 64;
    return ~((UL1 << beg_bit) - UL1);
}

UL right_border(int end){
    if(end >= MAXN) return ~UL0;
    int end_bit = (end % 64) + 1;
    if (end_bit == 64) return ~UL0;
    else return (UL1 << end_bit) - UL1;
}

int left_border_idx(int start) {
    return start / 64;
}

int right_border_idx(int end) {
    if(end >= MAXN) return right_border_idx(MAXN - 1);
    return end / 64;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, start, end, rep;

    while(cin >> n >> m && (n != 0 || m != 0)) {
        bool conflict = false;
        ms(sched, 0);
        for(int i = 0; i < n; ++i) {
            cin >> start >> end;
            --end;
            if (conflict) continue;
            int lo = left_border_idx(start);
            int hi = right_border_idx(end);
            UL lo_bm = left_border(start);
            UL hi_bm = right_border(end);
            if(lo == hi) {lo_bm = hi_bm = (lo_bm & hi_bm); }
            if(sched[lo] & lo_bm) {conflict = true; continue;}
            if(sched[hi] & hi_bm) {conflict = true; continue;}
            sched[lo] |= lo_bm;
            sched[hi] |= hi_bm;

            for(int i = lo + 1; i < hi; ++i) {
                if(sched[i]) {conflict = true; continue;}
                sched[i] = ~UL0;
            }
        }

        for(int i = 0; i < m; ++i) {
            cin >> start >> end >> rep;
            int sz = end - start;

            if(conflict) continue;
            for(int j = start; j < MAXN; j += rep) {
                start = j; end = j + sz - 1;
                int lo = left_border_idx(start);
                int hi = right_border_idx(end);
                UL lo_bm = left_border(start);
                UL hi_bm = right_border(end);
                if(lo == hi) {lo_bm = hi_bm = (lo_bm & hi_bm); }
                if(sched[lo] & lo_bm) {conflict = true; continue;}
                if(sched[hi] & hi_bm) {conflict = true; continue;}
                sched[lo] |= lo_bm;
                sched[hi] |= hi_bm;

                for(int i = lo + 1; i < hi; ++i) {
                    if(sched[i]) {conflict = true; continue;}
                    sched[i] = ~UL0;
                }
            }
        }
        cout << (conflict ? "CONFLICT\n" : "NO CONFLICT\n");
    }
}
