#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<long long> vll;

vll nums;

ll max_n = 10000000000LL;

bool test(ll u){
	int alg;
	for(ll j = 1; j <= u; j*=10){
		alg = (u/j)%10;
		if(alg != 0 && alg != 1 && alg != 4 && alg != 9) return false;
	}
	return true;
}

void preprocess(){
	nums.push_back(0);
	ll sqr = 1, i = 1;
	while(sqr <= max_n){
		if(test(sqr) && sqr%i == 0) nums.push_back(sqr);
		i++; sqr = i*i;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	ll a, b;
	cin >> T;
	preprocess();
	 while(T--){
		cin >> a >> b;
		if(a == b){
			cout << test(a) << '\n';
			continue;
		}
		vll::iterator first = lower_bound(nums.begin(), nums.end(),a), last = lower_bound(nums.begin(), nums.end(),b);
		cout << (int)(last - first) + (*last == b) << '\n';
		
	}
}
