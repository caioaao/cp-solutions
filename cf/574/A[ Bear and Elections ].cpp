#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

#define MAXN 110


L n, li, curr;

priority_queue<int> pq;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


    while(cin >> n)
    {
        n--;
        cin >> li;
        while(!pq.empty()) pq.pop();
        for(int i = 0; i < n; ++i)
        {
            cin >> curr;
            pq.push(curr);
        }

        L ans = 0;
        while(1)
        {
            curr = pq.top();
            pq.pop();
            if(curr < li)
                break;
            --curr;
            ++li;
            ++ans;
            pq.push(curr);
        }
        cout << ans << &#39;\n&#39;;
    }
}
