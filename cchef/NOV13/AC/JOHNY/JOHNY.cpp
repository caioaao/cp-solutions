#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;


int main(){
	ios_base::sync_with_stdio(false);
	int T, N, k;
	int songs[101];
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> songs[i];
		}
		cin >> k;
		k = songs[k-1];
		int pos = 1;
		for(int i = 0; i < N; i++) if(songs[i] < k) pos++;
		cout << pos << '\n';
	}
}
