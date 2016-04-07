#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, d, m;
	vector<int> prices;
	while(cin >> n >> d){
		prices.assign(n,0);
		for(int i = 0; i < n; i++) cin >> prices[i];
		cin >> m;
		sort(prices.begin(), prices.end());
		int price = (m > n ? -((m-n)*d) : 0);
		for(int i = 0; i < min(m, n); i++){
			price+=prices[i];
		}
		cout << price << &#39;\n&#39;;
	}
}
