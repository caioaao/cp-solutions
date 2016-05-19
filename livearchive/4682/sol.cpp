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
typedef pair<int,int> PI;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;


const int MAXN = 100100;
const int MAXB = 34;

#define _USE_NLOG
#ifdef _USE_LOG
#define LOG(x) cout << x
#define LOGB(x) LOG(bitset<MAXB>(x) << endl)
#else
#define LOG(x)
#define LOGB(x)
#endif

class Trie {
private:
    int nxt_idx;
    int ch[MAXB*MAXN][2];
public:
    Trie() {
        nxt_idx = 1;
        ms(ch, -1);
        this->put(0);
    }
    void put(L x) {
        int idx = 0;
        for(int i = 33; i >= 0; --i) {
            int b = !!(x & (1LL << i));
            if(ch[idx][b] == -1) {
                ch[idx][b] = nxt_idx++;
            }
            idx = ch[idx][b];
        }
    }
    L query(L x) {
        int idx = 0;
        L ans = 0;
        for(int i = 33; i >= 0; --i) {
            int bx = !!(x & (1LL << i));
            if(0 == bx) {
                if(ch[idx][1] != -1) {
                    ans |= (1LL << i);
                    idx = ch[idx][1];
                }
                else idx = ch[idx][0];
            }
            else {
                if(ch[idx][0] != -1) {
                    ans |= (1LL << i);
                    idx = ch[idx][0];
                }
                else idx = ch[idx][1];
            }
        }
        LOG("best for " << x << " is " << ans << endl);
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    Trie *t = new Trie();

    L acc = 0;
    L ans = 0;

    for(int i = 0; i < n; ++i) {
        L x;
        cin >> x;
        acc ^= x;
        ans = max(ans, t->query(acc));
        t->put(acc);
    }
    cout << ans << '\n';
    LOGB(ans);
    delete t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    for(int i = 0; i < t; ++i) {
        solve();
    }
}
