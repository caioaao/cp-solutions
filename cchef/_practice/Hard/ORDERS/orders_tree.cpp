#include <vector>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
	node *p, *l, *r;
	node(node p, node l, node r){
		p = p; l = l; r = r;
	};
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
		printf("\n");
	}
}
