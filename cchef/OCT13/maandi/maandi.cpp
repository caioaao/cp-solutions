#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

typedef map<int, bool> mib;
typedef vector<int> vi;



bool hasIt(int x){
	int alg;
	for(int j = 1; j <= x; j*=10){
		alg = ((x/j)*j-(x/(j*10))*j*10)/j;
		//cout << alg;
		if(alg == 7 || alg == 4){
			return true;
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	int ans;
	int t, x;
	cin >> t;
	//cout << hasIt(10000400) << endl;
	while(t--){
	//while(false){
		ans = 0;
		cin >> x;
		
		for(int i = 1; i <= sqrt(x); i++){
			if(x%i == 0){
				if(hasIt(i)) ans++;
				if(i != x/i && hasIt(x/i)) ans++;
			}
		}
		cout << ans << '\n';
	}
}
