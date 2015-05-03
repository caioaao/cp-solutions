#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

bool reverse_sort(ulli i, ulli j){ return (j<i);}

int main(){
	ulli M, Pi;
	int N, T;
	cin >> T;

	for(int testcase=0; testcase < T; testcase++){
		vector<ulli> P;
		cin >> N >> M;
		for(int i = 0; i < N; i++){
			cin >> Pi;
			P.push_back(Pi);
		}
		sort(P.begin(),P.end(), reverse_sort);
		ulli amt = 0;
		int plates = 0;
		while(amt < M && plates < N){
			amt += P[plates];
			// cout << amt << endl;
			plates++;
		}
		if (amt < M)
			cout << -1 << '\n';
		else
			cout << plates << '\n';
	}
}