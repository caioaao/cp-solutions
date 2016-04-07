#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, aux, tot, ans;
	while(cin >> n >> m){
		tot = 0;
		ans = 0;
		for(int i = 0; i < n; i++){
			cin >> aux;
			if(tot + aux > m){
				ans++;
				tot = 0;
			}
			tot += aux;
		}
		if( tot > 0) ans++;
		cout << ans << &#39;\n&#39;;
	}
}
