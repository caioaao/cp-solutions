#include <iostream>
#include <algorithm>

using namespace std;

int nums[100010], n;
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	
	while(t--){
		cin >> n;
	
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		sort(nums,nums+n);
		int i = 0, j = n-1;
		while(i != j){
			if(i > j) break;
			if(i != 0) cout << ' ';
			cout << nums[i];
			if( i != j) cout << ' ' << nums[j];
			i++; j--;
		}
		if(i == j){
			if(n > 1)cout << ' ';
			cout << nums[i];
		} 
		cout << '\n';
	}
}
