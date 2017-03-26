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
#include <set>
#include <random>

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
#define MAX_P 1000
VL primes;
bitset<MAX_P> is_p;

void sieve() {
    is_p.set();
    primes.reserve(MAX_P);
    for(L i = 3; i < MAX_P; i += 2) {
        if(is_p[i]) {
            primes.pb(i);
            for(L j = i + i; j < MAX_P; j += i) is_p.reset(j);
        }
    }
}

bool dvds(L v, L p, L b)
{
    L mod = 0;

    for(L i = 32; i >= 0; --i) {
        mod = ((mod * b)%p +  !!(v & (1LL << i)))%p;
    }

    return (mod == 0);
}

L d(L v, L b){
    // cout << '(' << v <<',' << b << ')' << vp << '\n';
    for(L i = 0; i < (L)primes.sz(); ++i){
        if(dvds(v, primes[i], b)) return primes[i];
    }
    return -1;
}

VL mk_ds(L v){
    VL ds;
    for(L i = 2; i <= 10; ++i) {
        L nd = d(v, i);
        if(nd == -1) break;
        else ds.pb(nd);
    }
    return ds;
}
void prb(L n, L v) {
    for(L i = n - 1; i >= 0; --i) cout << (!!((1LL << i) & v));
}

set<L> used;

L getrand(L n) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<L> dist(0, (1LL << (n-2)) - 1);
    L r = dist(rd);
    while(used.find(r) != used.end()){
        r = dist(rd);
    }
    return r;
}

void solve(L n, L j) {
    L ini_m = 1 | (1LL << (n - 1));
    for(L i = 0; i < j; ++i)
    {
        while(true) {
            L v = (getrand(n) << 1) | ini_m;;
            VL ds = mk_ds(v);
            if(ds.size() == 9) {
                prb(n, v);
                cout << ' ';

                for(L i = 0; i < 9; ++i) cout << ' ' << ds[i];
                cout << '\n';
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    L t;
    cin >> t;
    for(L i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":\n";
        L n, j;
        cin >> n >> j;
        solve(n,j);
    }
}
