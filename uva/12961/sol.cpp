#include <iostream>
using namespace std;

typedef long long L;

#define MAXN 30010

int n, k;
L mat[MAXN];

int rnk()
{
    int ans = 0;

    for(int j = 0; j < k; ++j)
    {
        L bm = (1L << (k - j - 1));
        for(int i = j; i < n; ++i)
        {
            if(mat[i] & bm)
            {
                swap(mat[i], mat[j]);
                break;
            }
        }

        if(!(mat[j] & bm))
        {
            break;
        }
        ++ans;

        for(int i = j + 1; i < n; ++i)
        {
            if(mat[i] & bm)
            {
                mat[i] ^= mat[j];
            }
        }
    }

    return ans;
}

int main() {

    L aux;

    while(cin >> n >> k)
    {
        for(int i = 0; i < n; ++i)
        {
            mat[i] = 0;
            for(int j = 0; j < k; ++j)
            {
                cin >> aux;
                if(aux & 1)
                {
                    mat[i] |= (1L << j);
                }
            }
        }
        if(n > k && rnk() == k)
        {
            cout << "N\n";
        }
        else
        {
            cout << "S\n";
        }
    }

    return 0;
}
