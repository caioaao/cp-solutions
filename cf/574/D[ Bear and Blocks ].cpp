#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

typedef long long L;

int n;
L h[MAXN], dL[MAXN], dR[MAXN];


int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) cin >> h[i];
    
    dL[0] = 1;
    for(int i = 1; i < n; ++i)
        dL[i] = min(dL[i-1] + 1, h[i]);
        
    dR[n-1] = 1;
    for(int i = n-2; i >= 0; --i)
        dR[i] = min(dR[i + 1] + 1, h[i]);
        
    L ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, min(dL[i], dR[i]));
        
    cout << ans << &#39;\n&#39;;       
}