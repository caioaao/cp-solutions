#include <iostream>
using namespace std;

#define MAXN 1010

typedef long long L;
int n;
L c[MAXN];

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> c[i];

        int ans = 1;
        L s = c[0];

        for(int i = 1; i < n - 1; ++i) {
            if(s + c[i] < c[i + 1]) {
                ++ans;
                s += c[i];
            }
        }

        ans += n > 1;

        cout << ans << '\n';
    }
    return 0;
}
