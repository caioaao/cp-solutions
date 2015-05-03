#include <iostream>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	while(cin >> n){
		n %= 1 + 2 + 3;
		if(n == 0 || n == 1 || n == 3) cout << "yes\n";
		else cout << "no\n";
	}
}
