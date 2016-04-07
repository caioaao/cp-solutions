#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 100100
#define MAXK 12

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define LSOne(S) (S & (-S))
class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  void init (int n) { ft.assign(n + 1, 0); }

  L rsq(int b) {                                     // returns RSQ(1, b)
    L sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  L rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, L v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int n, k;
int a[MAXN];

FenwickTree ft[MAXK];

L calc(void) {
    ++k;
    for(int i = 0; i <= k; ++i) ft[i].init(n + 1);
    ft[0].adjust(n + 1, 1);
    for(int i = n - 1; i >= 0; --i) {
        // cout << i << &#39;:&#39; << a[i] << &#39;\n&#39;;
        for(int j = k; j >= 1; --j) {
            ft[j].adjust(a[i], ft[j - 1].rsq(a[i] + 1, n + 1));
            // cout << "> k=" << j << ": " << ft[j].rsq(a[i], a[i]) << &#39;\n&#39;;
        }
        // cout << &#39;\n&#39;;
    }

    return ft[k].rsq(1, n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> k) {
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << calc() << &#39;\n&#39;;
    }
}
