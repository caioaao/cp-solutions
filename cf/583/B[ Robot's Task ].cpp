#include <bits/stdc++.h>


#define MAXN 1010

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

int n;
int v[MAXN];
int grabbed[MAXN];
int amt_i, amt_g;
void try_grab(int i)
{
    if(!grabbed[i])
    {
        if(amt_i >= v[i])
        {
            ++amt_i;
            grabbed[i] = 1;
            ++amt_g;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int ans;
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        memset(grabbed, 0, sizeof(grabbed));
        ans = 0;
        amt_g = 0;
        amt_i = 0;
        int dir = 0;
        while(amt_g < n)
        {
            if(dir == 0)
            {
                for(int i = 0; i < n; ++i)
                {
                    try_grab(i);
                }
            }
            else
            {
                for(int i = n-1; i >= 0; --i)
                {
                    try_grab(i);
                }
            }
            dir = !dir;
            if(amt_g < n) ++ans;
        }
        cout << ans << &#39;\n&#39;;
    }
}
