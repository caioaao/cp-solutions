#include <bits/stdc++.h>


#define MAXS 500
#define MAXN 10
#define MAXP 400

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

L memo[MAXP][MAXS][MAXN];

L dp(int curr, int len, int n)
{
    if(curr == n*12) return 0;
    
    L &ans = memo[curr][len][n];
    
    if(ans == -1)
    {
        int delt = n*12 - curr;
        ans = delt / len + dp(curr + 1, len, n);
    }

    return ans;
}

L solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int len = s.length() + 1;


    for(size_t i = 0; i < s.length(); ++i)
    {
        if(s[i] == 'T') len++;
    }
    cout << len << ' ';    
    return dp(0, len, n);
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
    memset(memo, -1, sizeof memo);
    while(t--)
    {
        cout << solve() << '\n';
    }
}
