#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;
typedef vector<int> vi;
typedef long long ll;

vi bags;
vector<vi> arrms;

int main(){
	ios_base::sync_with_stdio(false);
	int n, c;
	cin >> n;
	while(n != 0){
		bags.clear();
		arrms.clear();
		
		for(int i = 0; i < n; i++){
			cin >> c;
			bags.push_back(c);
		}
		sort(bags.begin(), bags.end());
		for(int i = 0; i < (int)bags.size(); i++){
			int men = INF, menId = -1;
			for(vector<vi>::iterator it = arrms.begin(); it != arrms.end(); ++it){
				if((int)it->size() < men && ((int)it->size() == 0 || *(it->end()-1) < bags[i])){
					men = it->size();
					menId = it-arrms.begin();
				}
			}
			if(menId == -1){
				arrms.push_back(vi());
				menId = arrms.size()-1;
			}
			arrms[menId].push_back(bags[i]);
		}
		cout << arrms.size() << '\n';
		
		for(vector<vi>::iterator i = arrms.begin(); i != arrms.end(); ++i){
			cout << *(i->begin());
			for(vi::iterator j = i->begin()+1; j != i->end(); ++j){
				cout  << ' ' << *j;
			}
			cout << '\n';	
		}
		cout << '\n';
		cin >> n;
	}
}
