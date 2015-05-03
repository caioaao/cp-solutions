#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int n_dec(ll d){
	int amt = 0;
	while(d){ d/=10;amt++; }
	return amt;
}


vll soma;
ll last = 0;

void gen(ll d){
	for(ll i = last+1; i <= d; i++){
		soma.push_back((soma[i-1]+((i*n_dec(i))%1000000007l))%1000000007l);
	}
	last = d;
}
int main(){
	ios_base::sync_with_stdio(false);
	last = 0;
	soma.push_back(0);
	int T;
	ll L, R;
	cin >> T;
	while(T--){
		cin >> L >> R;
		gen(R);
		cout << soma[R] - soma[L-1] << '\n';
	}
}
