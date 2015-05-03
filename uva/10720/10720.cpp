#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//Usa o teorema de Erdos Gallai, que dá uma condição suficiente para q uma sequencia de ints sejam sequencias de graus dos vértices de um grafo simples
typedef vector<int> vi;

bool bt(int x, int y){
	return x>y;
}

int main(){
	int n, d, sum, sumk;
	bool holds = true;
	vi vals;
	cin >> n;
	while(n != 0){
		holds = true;
		vals.clear();
		sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> d;
			vals.push_back(d);
			sum+=d;
		}
		if(sum%2 != 0) holds=false;
		else{
			sort(vals.begin(),vals.end(), bt);
			sum = 0;
			for(int k = 1; k <= n; k++){
				//cout << vals[k-1];
				sum += vals[k-1];
				sumk = k*(k-1);
				for(int i = k; i < n; i++){
					sumk += min(vals[i],k);
				}
				if(sumk < sum){
					holds = false; break;
				}
			}
		}

		cout << (!holds ? "Not p":"P") << "ossible" << endl;
		cin >> n;
	}
}
