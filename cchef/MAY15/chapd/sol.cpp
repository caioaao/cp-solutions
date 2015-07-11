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

L gcd(L a, L b) { return (b == 0 ? a : gcd(b, a%b)); }

void solve(void)
{
    L a, b;
    cin >> b >> a;
    L g = gcd(a, b);
    while(g != 1 && a != 1)
    {
        a /= g;
        g = gcd(a, b);
    }

    if(a == 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
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
