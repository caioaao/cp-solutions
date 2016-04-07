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

vector<L> anss;

void print()
{
    cout << anss.sz() << &#39;\n&#39;;
    for(vector<L>::iterator it = anss.begin(); it != anss.end(); ++it)
    {
        cout << (*it) << &#39; &#39;;
    }
    cout << &#39;\n&#39;;
}

vector<bool> isPrime;
void solve(int n)
{
    anss.clear();
    isPrime.assign(n + 1, true);
    L x;
    for(L i = 2; i <= n; ++i) if(isPrime[i])
    {
        x = i;
        while(x <= n)
        {
            anss.pb(x);
            x *= i;
        }
        for(int j = i + i; j <= n; j += i) isPrime[j] = 0;
    }
    print();
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while(cin >> n)
    {
        solve(n);
    }
}
