#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

vi vs;

void solve()
{
    int n;
    cin >> n;
    vs.assign(n,0);
    for(int i = 0; i < n; ++i)
        cin >> vs[i];

    sort(vs.begin(), vs.end(), greater<L>());
    L ans = 2;
    for(int i = 0; i < n - 1; ++i)
        ans += vs[i];
    if(vs.back() <= 1) cout << "-1\n";
    else cout << ans << '\n';
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
    while(t--)
    {
        solve();
    }
}
