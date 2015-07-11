#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define INF 1e6

#define MAXN 100010
#define MAXK 3

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;


int memo[MAXN][MAXK][2];
int memoized[MAXN][MAXK][2];
int memv[MAXN][MAXK][2];

int n, k, t;
string str;

#define v(x) (str[(x) - 1] - '0')
#define rv(x) ((x) + '0')

#define CURR id][lastDif][lastV

int dp(int id, int lastDif, int lastV)
{
    if(id - lastDif - 1 > k) return INF;
    if(id - 1 == n) return 0;

    
    if(memoized[CURR] == t) return memo[CURR];
    memoized[CURR] = t;
    int ans1 = dp( id + 1, lastDif, lastV) + (lastV != v(id));
    int ans2 = dp( id + 1, id - 1, !lastV) + (lastV == v(id));

    if(ans1 < ans2)
    {
        memo[CURR] = ans1;
        memv[CURR] = lastV;
    }
    else
    {
        memo[CURR] = ans2;
        memv[CURR] = !lastV;
    }
    
    return memo[CURR];
}

void print(int id, int lastDif, int lastV)
{
    if(id - 1 < n)
    {
        cout << memv[CURR];

        if(memv[CURR] == lastV)
        {
            print(id + 1, lastDif, lastV);
        }
        else
        {
            print(id + 1, id - 1, !lastV);
        }
    }
}

void solveS(void)
{
    int ans1 = dp(1, 0, 0);
    int ans2 = dp(1, 0, 1);
    
    if(ans1 < ans2)
    {
        cout << ans1 << '\n';
        print(1, 0, 0);
    }
    else
    {
        cout << ans2 << '\n';
        print (1, 0, 1);
    }
    
    cout << '\n';
}

void solveB(void)
{
    int ans = 0;
    int cnt = 0;
    int lastV = 4;

    for(int i = 1; i <= n; i++)
    {
        if(v(i) == lastV)
        {
            if(cnt == k + 1)
            {
                ++ans;
                str[i - 2] = rv(!lastV);
                cnt = 0;
            }
        }
        else
        {
            if(cnt == k + 1)
            {
                ++ans;
                str[i - 3] = rv(!lastV);
            }
            cnt = 0;
        }
        lastV = v(i);
        ++cnt;
    }

    if(cnt == k + 1)
    {
        ++ans;
        str[n-1] = rv(!lastV);
    }

    cout << ans << '\n';
    cout << str << '\n';
}

    
void solve(void)
{
    cin >> n >> k;
    cin >> str;

    if(k <= 2) solveS();
    else solveB();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    memset(memoized, -1, sizeof memoized);

    int C;
    cin >> C;
    for(t = 0; t < C; ++t)
    {
        solve();
    }
    
}
