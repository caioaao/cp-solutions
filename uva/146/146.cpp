#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;

char str[50];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> str;
	while(str[0] != '#'){
		if(next_permutation(str, str+(strlen(str))))
			cout << str;
		else cout << "No Successor";
		cout << "\n";
	
		cin >> str;
	}
}
