#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <iomanip>

#define INF 1e9

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int a, b, AdjMatrix[101][101];
	map<int, bool> pages;
	
	cin >> a >> b;
	int it = 1;
	while(a != 0 || b != 0){
		for(int i = 0; i < 101; i++)for(int j = 0; j < 101; j++) AdjMatrix[i][j] = INF;
		pages.clear();
		
		while(a != 0 || b != 0){
			AdjMatrix[a][b] = 1;
			cin >> a >> b;
		}
		
		for(int k = 1; k < 101; k++)
			for(int i = 1; i < 101; i++)
				for(int j = 1; j < 101; j++)
					AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k]+AdjMatrix[k][j]);

		int soma = 0, amt = 0;
		for(int i = 0; i < 101; i++){
			for(int j = 0; j < 101; j++){
				if(AdjMatrix[i][j] != INF && i != j){
					soma += AdjMatrix[i][j]; amt++;
				}
			}
		}
		
		cout << "Case " << it++ << ": average length between pages = " << fixed << setprecision(3) << (double)soma/amt << " clicks\n";
		
		cin >> a >> b;
	}
}
