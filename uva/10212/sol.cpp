#include <iostream>

using namespace std;
typedef unsigned long long L;

L cnt2, cnt5;

inline L getAmtNumInX(const L num, L x)
{
    L ans = 0;
    while(x > 0){
        x /= num;
        ans += x;
    }

    return ans;
}

inline void init(const L lo, const L hi)
{
    cnt5 = getAmtNumInX(5,hi) - getAmtNumInX(5, lo - 1);
    cnt2 = getAmtNumInX(2,hi) - getAmtNumInX(2, lo - 1);

    cnt5 = min(cnt2, cnt5);
    cnt2 = cnt5;
}

inline L removeMults(L x)
{
    while(x % 2 == 0 && cnt2 > 0)
    {
        x /= 2;
        --cnt2;
    }

    while(x % 5 == 0 && cnt5 > 0)
    {
        x /= 5;
        --cnt5;
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    L n, m;

    L ans;
    while(cin >> n >> m)
    {
        ans = 1;

        init(n - m + 1, n);

        for(L i = n - m + 1; i <= n; ++i)
        {
            ans *= removeMults(i);
            if(ans >= 10) ans %= 10;
        }

        cout << ans << '\n';
    }
}
