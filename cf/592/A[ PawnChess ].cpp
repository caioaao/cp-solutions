#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))

#define _NO_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

using namespace std;

typedef long long L;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

char mp[10][10];

int ma[2][8];

int check(int r, int c, char v) {
    if(v == mp[r][c]) {
        if(v == &#39;W&#39;) {
            for(int i = r -1; i >= 0; --i) {
                if(mp[i][c] != &#39;.&#39;) return -1;
            }
            return r;
        }
        else {
            for(int i = r + 1; i < 8; ++i) {
                if(mp[i][c] != &#39;.&#39;) return -1;
            }
            return 7 - r;
        }
    }
    else return -1;
}

int bst[256];

void add(char c, int x){
    bst[c] = min(bst[c], x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            cin >> mp[i][j];
        }
    }
    bst[&#39;A&#39;] = bst[&#39;B&#39;] = 10;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            int a = check(i,j, &#39;W&#39;);
            int b = check(i,j, &#39;B&#39;);
            // cout << i << &#39; &#39; << j << &#39;:&#39; << a << &#39;,&#39; << b << &#39;\n&#39;;

            if(a != -1) add(&#39;A&#39;, a);
            if(b != -1) add(&#39;B&#39;, b);
        }
    }

    if(bst[&#39;A&#39;] <= bst[&#39;B&#39;])
    cout << &#39;A&#39;<< &#39;\n&#39;;
    else cout << &#39;B&#39; << &#39;\n&#39;;
}
