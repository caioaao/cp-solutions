#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size
#define MOD 1000003

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

L n, l, r;

L memo[2][10010];

L dp(int x, int y)
{
    bool k = 0;

    memset(memo, 0, sizeof memo);

    
    for(int i = 0; i < x; i++, k = !k ){
        for(int j = 1; j <= y; j++){
            memo[k][j] = memo[!k][j] + memo[k][j - 1] + 1;
            if(memo[k][j] >= MOD) memo[k][j] %= MOD;
        }
    }


    return memo[!k][y];
}
    

L solve()
{
    memset(memo, -1, sizeof memo);
    
    L a = n;
    L b = r - l + 1;
    
    return dp(a, b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while(T--){
        cin >> n >> l >> r;
        cout << solve() << '\n';
    }
}
