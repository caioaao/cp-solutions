#include <iostream>
#include <algorithm>

//~ #define ASSERT(X) if(X) int aux = 2/0;

using namespace std;
string dp(int id, int kL, string s){
	if(kL == 0 || id == (int)s.length()) return s;
	int dist = 0;
	int mI = id;
	for(int i = id+1; i-id <= kL && i < (int)s.length(); i++){
		if(s[mI] < s[i]){
			mI = i;
			dist = i - id;
		}
	}
	//~ ASSERT(dist > kL);
	string aux = s;
	for(int i = mI; i > id; i--){
		swap(aux[i],aux[i-1]);
	}
	return dp(id+1, kL - dist, aux);
}
int main(){
	ios_base::sync_with_stdio(false);
	int k;
	string n, ans;
	while(cin >> n >> k){
		ans = dp(0, k, n);
		
		cout << ans << &#39;\n&#39;;
	}
}
