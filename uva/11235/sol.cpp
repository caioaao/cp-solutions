#include <bits/stdc++.h>

#define MAXA 200100
#define OFFSA 100000
#define MAXN 100100
#define MAXQ 100100

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


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define cl(x) ((x) * 2)
#define cr(x) (cl(x) + 1)

namespace rmq
{
    int n;
    int st[MAXN * 8];

    void build_(int (&vs_)[MAXN], int x, int l, int  r)
    {
        if(l == r) st[x] = vs_[l];
        else
        {
            build_(vs_, cl(x), l, (l + r) / 2);
            build_(vs_, cr(x), (l + r) / 2 + 1, r);
            st[x] = max(st[cl(x)], st[cr(x)]);
        }
    }
    
    void build(int (&vals_)[MAXN], int n_)
    {
        n = n_;
        build_(vals_, 1, 0, n - 1);
    }

    int rmq_(int x, int l, int r, int a, int b)
    {
        if(l > b || r < a) return 0;
        if(l >= a && r <= b) return st[x];
        return max(rmq_(cl(x), l, (l + r)/2, a, b),
                   rmq_(cr(x), (l + r)/2 + 1, r, a, b));
    }
    
    int rmq(int a, int b)
    {
        return rmq_(1, 0, n - 1, a, b);
    }
};



//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

L vs[MAXN];
int begV[MAXA];
int endV[MAXA];
int idV[MAXA];
int cntV[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, q, currId, currV, lastV;
    int ans;
    
    while(cin >> n >> q)
    {
        memset(cntV, 0, sizeof cntV);

        cin >> vs[0];
        vs[0] += OFFSA;
        currId = 0;
        idV[vs[0]] = 0;
        begV[vs[0]] = 0;
        ++cntV[0];
        
        lastV = vs[0];

        for(int i = 1; i < n; ++i)
        {
            cin >> currV;
            currV += OFFSA;
            vs[i] = currV;

            if(currV != lastV)
            {
                endV[lastV] = i-1;
                begV[currV] = i;
                idV[currV] = ++currId;
            }

            ++cntV[currId];
            lastV = currV;
        }
        endV[lastV] = n - 1;
        rmq::build(cntV,currId+1);
        int i, j, a, b;
        while(q--)
        {
            cin >> i >> j;
            --i; --j;
            a = vs[i]; b = vs[j];

            if(idV[a] != idV[b])
            {
                // cout << endV[a] - i + 1 << ' ' << j - begV[b] + 1 << ' ';
                ans = max(endV[a] - i + 1, j - begV[b] + 1);
                if(idV[a] + 1 < idV[b])
                {
                    ans = max(ans, rmq::rmq(idV[a] + 1, idV[b] - 1));
                    // cout << rmq::rmq(idV[a] + 1, idV[b] - 1) << ' ';
                }
            }
            else
            {
                ans = j - i + 1;
            }
            
            cout << ans << '\n';
        }
    }
}
