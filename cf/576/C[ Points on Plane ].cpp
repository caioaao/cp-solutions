#include <bits/stdc++.h>

#define pb push_back
#define sz size

#define all(x) x.begin(), x.end()

using namespace std;
typedef int L;
typedef vector<L> ii;
typedef vector<L> vi;
typedef vector<ii> vii;


L n;

vector<vii> pts;

bool cmpy(const ii & lhs, const ii & rhs)
{
    if(lhs[1] < rhs[1]) return true;
    else if(lhs[1] > rhs[1]) return false;
    return lhs[0] < rhs[0];
}

void read(void)
{
    scanf("%d", &n);
    pts.assign(1010, vii());
    ii aux(3);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &aux[0], &aux[1]);
        aux[2] = i + 1;
        pts[aux[0] / 1000].pb(aux);
    }
}

void calc_path(void)
{
    bool r = false;
    for(int i = 0; i < pts.sz(); ++i)
    {
        if(pts[i].empty()) continue;
        sort(all(pts[i]), cmpy);

        if(r)
        {
            for(int j = 0; j < pts[i].sz(); ++j)
            {
                printf("%d ", pts[i][j][2]);
            }
        }
        else
        {
            for(int j = pts[i].sz() - 1; j >= 0; --j)
            {
                printf("%d ", pts[i][j][2]);
            }
        }
        r = !r;
    }
}


int main()
{
    read();
    calc_path();
}
