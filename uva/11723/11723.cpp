#include <iostream>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	ll r, n;
	cin >> r >> n;
	int caso = 1;
	while(r!=0){
		if(r > n*27)
			cout << "Case " << caso++ << ": " << "impossible\n";
		else
			cout << "Case " << caso++ << ": " << (r/n)-1 + (r%n > 0) << '\n';
		cin >> r >> n;
	}
}
