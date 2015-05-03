#include <vector>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
	node *p, *l, *r;
};
int main(){
	int t, n, s;
	cin >> t;
	for(int cont = 0; cont < t; cont++){
		cin >> n;

		vector<int> possibilidades;
		vector<int> posicoes;
		for(int cont2 = 0; cont2 < n; cont2++){
			scanf("%d ",&s);
			posicoes.push_back(s);
			possibilidades.push_back(cont2);
		}
		int *ans = new int[n];

		for(int i = n-1; i >0; i--){
			ans[i] = possibilidades[possibilidades.size() - (1 + posicoes[i])];
			remove(possibilidades.begin(), possibilidades.end(),ans[i]);// O(n!)
		ans[0] = *possibilidades.begin();
		for(int i = 0; i < n; i++){
			printf("%d ",ans[i]+1);
		}
		printf("\n");
	}
}
