#include <iostream>
#include <cstring>

#define MAX_N 1001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int T, N, a[MAX_N], b[MAX_N], sum;
	cin >> T;
	while(T--){
		cin >> N;
		sum = 0;
		memset(b, 0, sizeof b);
		for(int i = 0;  i < N; i++){
			cin >> a[i];
			for(int j = 0; j < i; j++){
				b[i] += (a[i] >= a[j]);
			}
			sum += b[i];
		}
		cout << sum << '\n';
	}
}
