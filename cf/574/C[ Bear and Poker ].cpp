#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 100010

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

L gcd(L a, L b){ return (b > 0 ? gcd(b, a%b) : a); }

L vals[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    L n, d;
    while(cin >> n)
    {
        cin >> d;
        vals[0] = d;
        for(int i = 1; i < n; ++i)
        {
            cin >> vals[i];
            d = gcd(d, vals[i]);
        }
        // cout << "gcd: " << d << &#39;\n&#39;;
        int i;
        for(i = 0; i < n; ++i)
        {
            // cout << (vals[i] / d) << &#39; &#39;;
            vals[i] /= d;
            while(vals[i] % 2 == 0) vals[i] /= 2;
            while(vals[i] % 3 == 0) vals[i] /= 3;
            if(vals[i] != 1) break;
        }
        if(i == n) cout << "Yes\n";
        else cout << "No\n";
    }
}
