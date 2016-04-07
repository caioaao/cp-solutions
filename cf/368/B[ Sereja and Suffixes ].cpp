#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, m;
	vector<int> vals, amt;
	bitset<100001>seenIt;
	
	while(cin >> n >> m){
		seenIt.reset();
		vals.assign(n,0);
		amt.assign(n+1,0);
		
		for(int i = 0; i < n; i++){
			cin >> vals[i];
		} 
		for(int i = n-1; i >= 0; i--){
			amt[i] = amt[i+1];
			if(!seenIt.test(vals[i])){
				seenIt.set(vals[i]);
				amt[i]++;
			}
		}
		int testIt;
		for(int i = 0; i < m; i++){
			cin >> testIt;
			cout << amt[testIt-1] << &#39;\n&#39;;
		}
	}
}
