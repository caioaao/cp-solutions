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

#define MAXN 50
#define EPS 1e-8

using namespace std;

typedef long long L;
typedef double D;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

int n;
D results[MAXN][MAXN][MAXN];
int bst[MAXN][MAXN][MAXN];

void print(int i, int j, int k) {
    if(k >= 0) {
        print(i, bst[k][i][j], k - 1);
        cout << ' ' << j + 1;
    }
    else {
        cout << i + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n) {
        ms(bst, -1);
        ms(results, 0);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i != j) {
                    cin >> results[0][i][j];
                }
                else {
                    results[0][i][i] = 1;
                }
                bst[0][i][j] = i;
            }
        }
        for(int l = 1; l < n; ++l) {
            for(int k = 0; k < n; ++k) {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < n; ++j) {
                        if(results[l][i][j] < results[l - 1][i][k] * results[0][k][j]) {
                            results[l][i][j] = results[l - 1][i][k] * results[0][k][j];
                            bst[l][i][j] = k;
                        }
                    }
                }
            }
        }

        D bst = 0;
        int bstLen = 0;
        int bstI;

        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                if(results[k][i][i] > 1.01) {
                    bst = results[k][i][i];
                    bstLen = k + 1;
                    bstI = i;
                    goto out;
                }
            }
        }
    out:
        LOG(bstLen << ' ' << bst<< ' ' << bstI << '\n');

        if(bstLen == 0 || bst < 1.01) {
            cout << "no arbitrage sequence exists\n";
        }
        else{
            print(bstI, bstI, bstLen - 1);
            cout << '\n';
        }
    }
}
