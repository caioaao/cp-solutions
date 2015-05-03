#include <map>
#include <vector>
#include<string>
#include<cstdio>
#include<iostream>

using namespace std;

typedef vector<int> vi;

map<string, int> names;
vi size;
vi pset;

void initSet(int N){pset.assign(N,0);size.assign(N,1); for(int i = 0; i < N; i++) pset[i] = i;}
int findSet(int A){return (pset[A] == A) ? A : (pset[A] = findSet(pset[A]));}
bool isSameSet(int a, int b){return findSet(a) == findSet(b);}
int sizeSet(int a){return size[findSet(a)];}
int unionSet(int a, int b){
	if(!isSameSet(a,b)) size[findSet(b)] += size[findSet(a)];
	pset[findSet(a)] = findSet(b); return sizeSet(b);
}

int main(){
	int test, n, nome_n, na, nb;
	string nomeA, nomeB;
	cin >> test;
	while(test--){
		cin >> n;
		names.clear();
		initSet(2*n+1);
		nome_n = 1;
		while(n--){
			cin >> nomeA >> nomeB;
			//scanf("%s %s\n",&nomeA, &nomeB);
			if(!names.count(nomeA)) {names[nomeA] = na = nome_n++;}
                        else na = names[nomeA];
                        
			if(!names.count(nomeB)) {names[nomeB] = nb = nome_n++;}
                        else nb = names[nomeB];

			cout << unionSet(na,nb) << endl;
		}
	}
}
