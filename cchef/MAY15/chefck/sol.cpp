#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MOD 1000000007
#define INF 1000000009

#define MAXN 10000010

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;


#define mod(x, y) (((x) >= (y) || (x <= -(y))) ? (x)%(y) : (x))


L vs[MAXN];
int lv[MAXN];
int rv[MAXN];

int n, k, q;
L a, b, c, d, e, f, r, s, t, m;
int l1, la, lc, lm, d1, da, dc, dm;

void genvs(void);
void genqs(void);

void solve(void)
{

    cin >> n >> k >> q;
    cin >>  a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> vs[1];
    cin >>  l1 >> la >> lc >> lm >> d1 >> da >> dc >> dm;

    genvs();
    genqs();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    solve();
}


void genvs(void)
{
    L tToX = mod(t*t, s);

    vs[0] = INF;
    vs[n+1] = INF;
    for(int x = 2; x <= n; ++x)
    {
        if(tToX <= r)
        {
            vs[x] = mod(mod(a*vs[x-1]*vs[x-1], m) + mod(b*vs[x-1], m) + c, m);
        }
        else
        {
            vs[x] = mod(mod(a*vs[x-1]*vs[x-1], m) + mod(b*vs[x-1], m) + f, m);
        }
        tToX = mod(tToX*t, s);
        cout << ' ' << vs[x];
    }
    cout << '\n';
}


void genqs(void)
{
    int lv, rv;
    for(int i = 0; i < q; ++i)
    {
        l1 = mod(mod(la * l1, lm) + lc, lm);
        d1 = mod(mod(da * d1, dm) + dc, dm);
        lv = l1 + 1 - 1;
        rv = min(lv + k - 1 + d1, n) - 1;
        
    }
}
