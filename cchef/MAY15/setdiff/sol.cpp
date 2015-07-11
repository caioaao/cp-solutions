#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define mod 1000000007

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;


#define md(a) ((((a) >= mod) || ((a) <= -mod)) ? (a)%mod : (a))

vi vs;
map<L,L> amt;
typedef map<L,L>::iterator mit;
typedef map<L,L>::reverse_iterator mrit;

inline L pot(L a, L b) {
    L x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=md(x*y);
        }
        y = md(y*y);
        b /= 2;
    }

    return x;
}


void solve(void)
{
    int n;
    L aux;
    cin >> n;
    amt.clear();
    for(int i = 0; i < n; ++i)
    {
        cin >> aux;
        if(!amt.count(aux)) amt[aux] = 0;
        amt[aux]++;
    }

    L lv = 1;
    L p;
    L ans = 0;

    for(mit it = amt.begin(); it != amt.end(); ++it)
    {
        p = pot(2, it->ss);
        ans = md(ans + md(it->ff * md((p - 1) * lv)));

        lv = md(p*lv);
    }


    lv = 1;
    for(mrit rit = amt.rbegin(); rit != amt.rend(); ++rit)
    {
        p = pot(2, rit->ss);
        ans = md(ans - md(rit->ff * md((p - 1) * lv)));

        lv = md(p*lv);
    }

    ans = md(ans + mod);

    cout << ans << '\n';
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
