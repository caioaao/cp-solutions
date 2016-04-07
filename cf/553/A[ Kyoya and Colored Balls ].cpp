#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MOD 1000000007
#define MAXK 1010

#define NOR(x) ((((x) <= -MOD) || ((x) >= MOD)) ? ((x)%MOD) : (x))

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

L memod[MAXK][MAXK];

L distr(L x, L y)
{
    if(0 == x) return 1;
    if(0 == y) return 0;

    if(memod[x][y] == -1)
    {
        memod[x][y] = distr(x-1,y) + distr(x,y-1);
        memod[x][y] = NOR(memod[x][y]);
    }

     return memod[x][y];
}

int k, n;

int nk[MAXK];

L memo[MAXK][MAXK];

L dp(L cor, L bolas)
{
    if(cor == -1) return 1;
    if(memo[cor][bolas] == -1)
    {
        L k0, k1;
        k1 = (bolas > 0 ? dp(cor, bolas - 1) : 0);

        k0 = dp(cor - 1, nk[cor] + bolas - 1);
        k0 = NOR(k0) * distr(nk[cor] - 1, bolas + 1);;

        memo[cor][bolas] = NOR(k0) + NOR(k1);

        memo[cor][bolas] = NOR(memo[cor][bolas]);
    }

    return memo[cor][bolas];
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(memod, -1, sizeof memod);

    while(cin >> k)
    {
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < k; ++i)
        {
            cin >> nk[i];
        }
        cout << dp(k-1, 0) << &#39;\n&#39;;
    }
}
