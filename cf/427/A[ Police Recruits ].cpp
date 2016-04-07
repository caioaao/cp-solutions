#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	while(cin >> n){
		int pols = 0, ans = 0, x;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(x == -1){
				if(pols == 0) ans++;
				else pols-=1;
			}
			else pols += x;
		}
		cout << ans << &#39;\n&#39;;
	}
}
