#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 3000

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;


int n;
int vals[MAXN];
int memo_l[MAXN][MAXN];
int memo_h[MAXN][MAXN];

int dp_l(int idx, int last) {
    if(idx == n) return 0;
    int &ans = memo_l[idx][last];
    if(-1 == ans) {
        ans = dp_l(idx + 1, last);
        if(vals[idx] < vals[last]) {
            ans = max(ans, 1 + dp_l(idx + 1, idx));
        }
    }
    return ans;
}

int dp_h(int idx, int last) {
    if(idx == n) return 0;
    int &ans = memo_h[idx][last];
    if(-1 == ans) {
        ans = dp_h(idx + 1, last);
        if(vals[idx] > vals[last]) {
            ans = max(ans, 1 + dp_h(idx + 1, idx));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> vals[i];
        }

        memset(memo_h, -1, sizeof memo_h);
        memset(memo_l, -1, sizeof memo_l);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, 1 + dp_l(i + 1, i) + dp_h(i + 1, i));
        }
        cout << ans << '\n';
    }
}
