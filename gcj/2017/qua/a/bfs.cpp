#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))

using namespace std;

typedef long long L;
typedef unsigned long long UL;
typedef double D;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;

#define _NO_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

int str_to_state(const string& s) {
    int state = 0;
    for(int i = 0; i < s.sz(); ++i) {
        if(s[i] != '+') state |= (1 << i);
    }
    return state;
}
const int MAXN= (1 << 15);

int visited[MAXN];

int swap(int state, int beg, int k) {
    for(int i = beg; i < beg + k; i++) state ^= (1 << i);
    return state;
}

int k, state_sz;

queue<int>q;

int bfs(int state) {
    ms(visited, -1);
    visited[state] = 0;
    while(!q.empty()) q.pop();
    q.push(state);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int i = 0; i + k <= state_sz; ++i){
            int nxt = swap(curr, i, k);
            if(visited[nxt] == -1) {
                visited[nxt] = visited[curr] + 1;
                q.push(nxt);
            }
        }
    }

    return visited[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string s;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        cin >> s >> k;
        state_sz = s.sz();
        int state = str_to_state(s);
        int ans = bfs(state);
        if(ans == -1) cout << "IMPOSSIBLE";
        else cout << ans;
        cout << '\n';
    }
}
