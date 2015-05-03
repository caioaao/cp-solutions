#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

set<int> jaset, jiset;
vector<int> fset;

int main(){
	ios_base::sync_with_stdio(false);
	
	long long jack, jill, x;
	vector<int>::iterator it;
	
	cin >> jack >> jill;
	while(jack != 0 || jill != 0){
		jaset.clear(); jiset.clear();
		fset = vector<int>(1000000);
		for(int i = 0; i < jack; i++){
			cin >> x;
			jaset.insert(x);
		}
		
		for(int i = 0; i < jill; i++){
			cin >> x;
			jiset.insert(x);
		}
		
		set_intersection(jaset.begin(),jaset.end(),jiset.begin(), jiset.end(), fset.begin());
		int sum = 0;
		for(vector<int>::iterator i = fset.begin(); *i != 0; ++i){
			sum++;
		}
		cout << sum << '\n';
		
		cin >> jack >> jill;
	}
}
