#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T, n;
	string line;
	vector<bool> scs;
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		cout << "Case " << caso << ": ";
		
		cin >> n >>line;
		scs.assign(n,0);
		long long amt = 0;
		for(int i = 0; i < n; i++){
			if((i > 0 && !scs[i-1] && line[i-1] == '.' ) || (i == n-1 && !scs[i] && line[i] == '.')){
				scs[i] = true; 
				if(i-1 > 0) scs[i-1] = true; 
				if(i+1 < n)scs[i+1] = true;
				amt++;
			}
		}
		cout << amt << '\n';
	}
}
