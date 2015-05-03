#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	
	vi lis,last, num;
	int x, i = 1, max_lis = 0;
	cin >> x;
	num.push_back(x);
	lis.push_back(1);
	last.push_back(0);
	
	while(cin >> x){
		num.push_back(x);
		lis.push_back(1);
		last.push_back(i);
		for(int j = i; j >= 0; j--){
			if(num[j] < x && lis[j]+1 > lis[i]){
				lis[i] = lis[j]+1;
				last[i] = j;
			}
		}
		
		if(lis[i] >= lis[max_lis]) max_lis = i;
		
		i++;
	}
	//for(vi::iterator it = lis.begin(); it != lis.end(); ++it) cout << *it << ' ';
	cout << lis[max_lis] << "\n-\n";
	stack <int> toprint;
	i = max_lis;
	toprint.push(num[max_lis]);
	while(last[i] != i){
		toprint.push(num[last[i]]);
		i = last[i];
	}
	while(!toprint.empty()){
		cout << toprint.top() << '\n';
		toprint.pop();
	}
	
}
