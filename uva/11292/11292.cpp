#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;
vi dragons, knights;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, dummy;
	cin >> n >> m;
	while( n!= 0 || m != 0){
		int l = -1;
		long long sum = 0;
		
		dragons.clear(); knights.clear();
		
		for(int i = 0; i < n; i++){
			cin >> dummy;
			dragons.push_back(dummy);
		}
		for(int i = 0; i < m; i++){
			cin >> dummy;
			knights.push_back(dummy);
		}
		if(n > m){
			cout << "Loowater is doomed!\n";
			goto fim;
		}
		sort(dragons.begin(), dragons.end());
		sort(knights.begin(), knights.end());
		for(int i = 0; i < n; i++){
			bool hasIt = false;
			for(int j = l+1; j < m; j++){
				if(knights[j] >= dragons[i]){
					hasIt = true;
					sum += knights[j];
					l = j; break;
				}
			}
			if(!hasIt){
				cout << "Loowater is doomed!\n";
				goto fim;
			}
		}
		cout << sum << '\n';
		
		fim:
		cin >> n >> m;
	}
}
