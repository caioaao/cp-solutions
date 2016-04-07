#include <iostream>

using namespace std;
typedef long long ll;
ll n, t, c;
int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> t >> c){
		ll amtLine = 0, x, ans = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(x > t){
				if(amtLine >= c){
					ans+= amtLine - c + 1;
				}
				amtLine = 0;
			}
			else amtLine++;
		}
		if(amtLine >= c){
			ans +=  amtLine - c + 1;
		}
		cout << ans << &#39;\n&#39;;
	}
}
