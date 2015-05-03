#include <iostream>
#include <cstring>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,bool> ans; 

int a[110], n;
bool memoized[11][110];
ans memo[110][110];

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		memset(memoized, 0, sizeof memoized);
	}
}
