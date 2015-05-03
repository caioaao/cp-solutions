#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;
typedef long long ll;


ll lis[MAX_N], lds[MAX_N], heights[MAX_N], widths[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);
	int T, N;
	ll max_lis, max_lds;
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		cout << "Case " << caso << ". ";
		
		max_lis = max_lds = 0;
		
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> heights[i];
		}
		for(int i = 0; i < N; i++){
			cin >> widths[i];
			
			lis[i] = lds[i] = widths[i];
			for(int j = 0; j < i; j++){
				if(lis[j]+widths[i] > lis[i] && heights[j] < heights[i]){
					lis[i] = lis[j]+widths[i];
				}
				if(lds[j]+widths[i] > lds[i] && heights[j] > heights[i]){
					lds[i] = lds[j]+widths[i];
				}
			}
			max_lis = max(max_lis,lis[i]);
			max_lds = max(max_lds,lds[i]);
		}
		
		if(max_lis >= max_lds)
			cout << "Increasing (" << max_lis << "). Decreasing (" << max_lds << ").\n";
		else
			cout << "Decreasing (" << max_lds << "). Increasing (" << max_lis << ").\n";
	}
}
