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
#define MAXN 5000
#define MAXM 5000
int n, m;
vvi adj;
L ack[MAXN];
int as[MAXM];
int bs[MAXM];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m)
    {
        adj.assign(n, vi());
        memset(ack, 0, sizeof ack);
        int a,b;
        for(int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            --a;--b;

            as[i] = a;
            bs[i] = b;

            adj[a].pb(b);
            adj[b].pb(a);

            ++ack[a];
            ++ack[b];
        }

        L ans = -1;
        L currAns;

        for(int i = 0; i < m; ++i)
        {
            L bstC = -1;

            for(int k = 0; k < n; ++k)
            {
                bool knowsA = false, knowsB = false;

                for(int j = 0; j < (int)adj[k].sz(); ++j)
                {
                    if(adj[k][j] == as[i]) knowsA = true;
                    if(adj[k][j] == bs[i]) knowsB = true;
                }

                if(knowsA && knowsB)
                {
                    if(bstC == -1) bstC = ack[k];
                    else bstC = min(bstC, ack[k]);
                }
            }

            if(bstC >= 0)
            {
                currAns = ack[as[i]] + ack[bs[i]] + bstC - 6;
                if(ans >= 0)
                    ans = min(ans, currAns);
                else
                    ans = currAns;
            }
        }
        cout << ans << &#39;\n&#39;;
    }
}
