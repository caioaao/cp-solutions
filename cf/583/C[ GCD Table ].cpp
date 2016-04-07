#include <bits/stdc++.h>

#define MAXN 505

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


multiset<L> tbr;
vector<L> vals;
vector<L> ans;
int n;

L gcd(int a, int b){return (!b ? a : gcd(b, a % b)); }

void add_good(int v)
{
    for(int i = 0; i < (int)ans.sz(); ++i)
    {
        tbr.insert(gcd(ans[i], v));
        tbr.insert(gcd(ans[i], v));
    }
    ans.pb(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(cin >> n)
    {
        vals.assign(n * n,0);
        for(int i = 0; i < n * n; ++i)
        {
            cin >> vals[i];
        }
        sort(vals.begin(), vals.end(), greater<L>());
        ans.clear();
        tbr.clear();
        multiset<L>::iterator elm;
        for(int i = 0; i < n * n; ++i)
        {
            //cout << vals[i] << &#39;:&#39;;
            if((elm = tbr.find(vals[i])) != tbr.end())
            {
                //  cout << tbr.count(vals[i]) << &#39;.&#39;;
                tbr.erase(elm);
                //cout << tbr.count(vals[i]);
            }
            else
            {
                add_good(vals[i]);
            }
            //cout << ";\n";
        }

        for(int i = 0; i < n; ++i)
            cout << ans[i] << &#39; &#39;;
        cout << &#39;\n&#39;;
    }
}
