#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

#define MAX_N 10000000

using namespace std;

typedef long long ll;

ll A[MAX_N], n, L[MAX_N], L_id[MAX_N], P[MAX_N];

int main(){
	
	ll lis = 0, lis_end = 0, x;
	for(ll i = 0; cin >> x; i++){
		A[i] = x;
		int pos = lower_bound(L, L+lis, x) - L;
		L[pos] = x;
		L_id[pos] = i;
		P[i] = pos ? L_id[pos - 1] : -1;
		if(pos+1 > lis){
			lis = pos+1;
			lis_end = i;
		}
	}
	stack<int> toprint;
	cout << lis << "\n-\n";
	for(; P[lis_end] >= 0; lis_end = P[lis_end]) toprint.push(A[lis_end]);
	cout << A[lis_end] << '\n';
	while(!toprint.empty())cout << toprint.top() << '\n', toprint.pop();
}
