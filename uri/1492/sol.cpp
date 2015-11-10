#include <bits/stdc++.h>

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
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

UL memo[100][2];
UL memo_cnt[100][2];
UL num;

UL cnt(int bit_idx, bool is_pref_equal) {
    if(bit_idx == -1) return 1;

    UL &ans = memo_cnt[bit_idx][is_pref_equal];
    if(ans == (UL)-1) {
        if(is_pref_equal) {
            if((num & (1ULL << bit_idx)) != 0) {
                ans = cnt(bit_idx - 1, 0) + cnt(bit_idx - 1, 1);
            }
            else {
                ans  = cnt(bit_idx - 1, 1);
            }
        }
        else {
            ans = 2 * cnt(bit_idx - 1, 0);
        }
    }
    return ans;
}

UL dp(int bit_idx, bool is_pref_equal) {
    if(bit_idx == -1) return 0;

    UL &ans = memo[bit_idx][is_pref_equal];
    if((UL)-1 == ans) {
        if(is_pref_equal) {
            if((num & (1ULL << bit_idx)) != 0) {
                ans = dp(bit_idx - 1, 0) // choose 0
                    + (dp(bit_idx - 1, 1) + cnt(bit_idx - 1, 1)); // choose 1
            }
            else {
                ans  = dp(bit_idx - 1, 1); // choose 0
            }
        }
        else {
            ans = dp(bit_idx - 1, 0) // choose 0
                + dp(bit_idx - 1, 0) + cnt(bit_idx - 1, 0); // choose 0
        }
    }

    return ans;
}


L calc(UL x) {
    memset(memo, -1, sizeof(memo));
    memset(memo_cnt, -1, sizeof(memo_cnt));
    num = x;
    return dp(63, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    UL a, b;

    while(cin >> a >> b) {
        if(a > b) {
            swap(a, b);
        }

        cout << (calc(b) - calc(a - 1)) << '\n';
    }
}
