#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))

#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

#define MAXN 100010
#define MAXB 63

using namespace std;

typedef long long L;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

L ans ();
void forward_elimination();
void back_substitution();

#ifdef _USE_LOG
void log_mat();
#define LOG_MAT() log_mat()
#else
#define LOG_MAT()
#endif

int n;
L mat[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
    LOG_MAT();
    forward_elimination();
    LOG_MAT();
    back_substitution();
    LOG_MAT();
    cout << ans() << '\n';
}


void forward_elimination() {
    for(int i = 0; i < min(MAXB, n); ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(mat[i] < mat[j]) swap(mat[i], mat[j]);
        }
        if(!mat[i]) break;

        for(int j = i + 1; j < n; ++j){
            mat[j] = min(mat[j], mat[i] ^ mat[j]);
        }
    }
}


void back_substitution() {
    for(int i = n - 1; i >= 0; --i) {
        if(!mat[i]) continue;
        for(int j = 0; j < i; ++j) {
            mat[j] = min(mat[j], mat[i] ^ mat[j]);
        }
    }
}

L ans () {
    L ans = 0;
    for(int i = 0; i < n; ++i) ans ^= mat[i];
    return ans;
}

#ifdef _USE_LOG
void log_mat() {
    LOG("n:" << n << '\n');
    for(int i = 0; i < n; ++i) {
        LOG(bitset<MAXB>(mat[i]) << ' ' << setw(3) << msb[i] << '\n');
    }
}
#endif
