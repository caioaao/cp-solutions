#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<long long> vi;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	ll X;
	ll i = 0;
	vi xs;
	
	while(cin >> X){
		i++;
		xs.push_back(X);
	
		nth_element(xs.begin(),xs.begin()+(i/2),xs.end());
		
		if(i%2 == 0){
			nth_element(xs.begin(),xs.begin()+(i/2)-1,xs.end());
			cout << (xs[i/2]+xs[i/2-1])/2 << '\n';
		}
		else
			cout << xs[i/2] << '\n';
			
	}
}
