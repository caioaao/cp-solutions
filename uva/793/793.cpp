#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

int pset[1000001];

void initSet(lli N){for(lli i = 0; i < 1000001; i++) pset[i] = i;}
lli findSet(lli i){return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));}
bool isSameSet(lli i, lli j){return findSet(i) == findSet(j);}
void unionSet(lli i, lli j){pset[findSet(i)] = findSet(j); }

int main(){
	lli d, n, ci, cj, succ,nq;
	char op;
	cin >> d;
	for(lli i = 0; i < d; i++){
		if(i > 0) cout << endl;
		succ = 0; nq=0;
		scanf("%lld\n",&n);
		initSet(n+1);
		while(scanf("%c %lld %lld\n", &op, &ci, &cj) == 3){
			if(op == 'c') unionSet(ci,cj);
			else if(op == 'q'){
				nq++; if(isSameSet(ci,cj)) succ++;
			}
		}
		cout << succ << ',' << (nq-succ) << endl;
	}
	return 0;
}
