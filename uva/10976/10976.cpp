#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int k, x, y, amt;
	stringstream buffer;
	string line;
	while(cin >> k){
		amt = 0;
		for(x = k+1; x <= 2*k; x++){
			if((k*x)%(x-k) == 0){
				amt++;
				y = (k*x)/(x-k);
				buffer << "1/"<< k << " = 1/" << y << " + 1/" << x << '\n';
			}
		}
		cout << amt << '\n';
		for(int i = 0; i < amt; i++){
			getline(buffer,line);
			cout << line << '\n';
		}
	}
}
