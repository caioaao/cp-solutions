#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

struct colorArea{
	
};

int main(){
	ios_base::sync_with_stdio(false);
	
	int N;
	vector<vi> colors;
	
	while(cin >> N){
		colors.assign(N,vi(N,0));
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> colors[i][j];
			}
		}
	}
}
