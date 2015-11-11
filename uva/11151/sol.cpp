#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 1010

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int memo[MAXN][MAXN];

int solve(const string& str){
    int n = str.sz();

    for(int i = 0; i < n; ++i) {
        memo[i][i] = 1;
    }
    for(int i = 0; i + 1 < n; ++i) {
        memo[i][i+1] = (str[i] == str[i + 1]) + 1;
    }

    for(int l = 3; l <= n; ++l) {
        for(int i = 0, j = l - 1; j < n; ++i, ++j) {
            memo[i][j] = max(memo[i + 1][j], memo[i][j - 1]);

            if(str[i] == str[j]) {
                memo[i][j] = max(memo[i][j], 2 + memo[i + 1][j - 1]);
            }
        }
    }
    return memo[0][n - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string l;
    getline(cin,l);
    int n = atoi(l.c_str());
    while(n--) {
        getline(cin,l);
        cout << solve(l) << '\n';
    }
}
