#include <iostream>
#include <algorithm>

using namespace std;

int vals[101];

long long n, s, x;

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> s){
		x = 0;
		for(int i = 0; i < n; i++){
			cin >> vals[i];
			x+= vals[i];
		}
		if( x <= s){
			cout << "YES\n";
			continue;
		}
		
		sort(vals, vals+n);
		x = 0;
		for(int i = 0; i < n-1; i++) x+=vals[i];
		if(x <= s) cout << "YES\n";
		else cout << "NO\n";
	}
}
