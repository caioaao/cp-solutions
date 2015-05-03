#include <iostream>
#include <string>
#define MAX_N 15

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T, n, member;
	string dummy;
	cin >> T;
	
	for(int caso = 1; caso <= T; caso++){
		cout << "Case " << caso << ": ";
		
		cin >> n;
		for(int i = 0; i <= n/2; i++){
			cin >> member;
		}
		cout << member << '\n';
		getline(cin, dummy);
	}
}
