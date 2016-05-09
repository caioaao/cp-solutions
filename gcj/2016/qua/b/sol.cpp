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

inline string flip(string v, int i) {
    string v2 = v;
    for(int j = 0; j <= i; ++j) {
        if(v[j] == '-') v2[i - j] = '+';
        else v2[i - j] = '-';
    }
    return v2;
}

inline bool nok(const string& v) {
    for(int i = 0; i < v.size(); ++i) if(v[i] == '-') return true;
    return false;
}

int solve(string v, int n) {
    int f = 0;
    while(nok(v)) {
        int r0 = v[0];
        int ifl = 0;
        while(ifl < n && (v[ifl] == r0)) ++ifl;
        v = flip(v,--ifl);
        ++f;
    }
    return f;
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

        cout << solve(s, s.length());

        cout << endl;
    }
}
