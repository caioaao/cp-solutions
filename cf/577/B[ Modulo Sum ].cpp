#include <bits/stdc++.h>

#define MAXN 1001000
#define MAXM 1010

using namespace std;

int memo[MAXM][MAXM][2];
int v[MAXN];
int n, m;

bool dp(int id, int mod, bool chose)
{
    if(mod == 0 && chose) return true;
    if(id == n) return false;
    
    int &ans = memo[id][mod][chose];
    
    if(ans == -1)
    {
        ans = dp(id + 1, mod, chose) ||
              dp(id + 1, (mod + v[id])%m, true);
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; ++i) cin >> v[i];
        
        memset(memo, -1, sizeof memo);
        
        if(n >= m || dp(0, 0, 0)){
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";      
        }
    }
}