#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(){
	int t, r, si, ans, num;
	vi s;
	cin >> t;
	while(t--){
		cin >> r;
		s.clear(); ans = 0;
		for(int i = 0; i < r; i++){
			cin >> si;
			s.push_back(si);
		}
		sort(s.begin(),s.end());
		num = s[r/2];
		if(r%2 == 0) num = (num+s[r/2-1])/2;
		for(int i = 0; i < r; i++){
			ans += abs(num-s[i]);
		}
		cout << ans << '\n';
	}
	
}
