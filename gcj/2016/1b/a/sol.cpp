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

char cs[10] = {'Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G', 'I'};
int ord[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

VL c_occ(const string& s) {
    VL ans(30, 0);
    for(string::const_iterator it = s.begin(); it != s.end(); ++it) {
        ++ans[(*it) - 'A'];
    }
    return ans;
}
string nums[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void remove_letters(VL &occs, int n, int amt) {
    for(int ci = 0; ci < int(nums[n].length()); ++ci) {
        occs[nums[n][ci] - 'A'] -= amt;
    }
}

VL n_occ(VL occs) {
    VL r(10, 0);
    for(int i = 0; i < 30; ++i) {
        LOG(occs[i] << ' ');
    }
    LOG(endl);


    for(int i = 0; i < 10; ++i) {
        int n = ord[i];
        r[n] += occs[cs[n] - 'A'];
        LOG("r[" << n << "] = " << r[n] << endl);
        remove_letters(occs, n, occs[cs[n] - 'A']);

        for(int i = 0; i < 30; ++i) {
            LOG(occs[i] << ' ');
        }
        LOG(endl);


    }
    return r;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        string s;
        cin >> s;
        LOG("s = " << s << endl);
        VL nums = n_occ(c_occ(s));

        for(int i = 0; i < 10; ++i) {
            if(nums[i] > 0)
                cout << string(nums[i], i + '0');
        }
        cout << '\n';
    }
}
