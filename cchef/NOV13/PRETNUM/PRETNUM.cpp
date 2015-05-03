#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define SQN 1000001
#define MAX_N 1000000000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int T;
vi ps;
bitset <SQN> bs;
bitset<SQN>tested, good;
ll a, b;

inline int testPrime(ll num){
	if(num < SQN) return bs.test(num);
	for(int i = 0; i <(int)ps.size() && ps[i] <= sqrt(num); i++){
		if(num % ps[i] == 0) return 0;
	}
	return 1;
}

inline ll effPow(ll num, ll pot){
	ll ans = num;
	for(int i = 2; i <= pot; i*=2){
		ans = (ans*ans);
	}
	if(pot % 2 == 1) ans = (ans*num);
	return ans;
}


inline void genPs(){
	bs.set();
	bs.reset(0); bs.reset(1);
	for(int i = 2; i < SQN; i++){
		if(bs.test(i)){
			ps.push_back(i);
			for(int j = i+i; j < SQN; j+=i) bs.reset(j);
		}
	}
}

inline void process(){
	tested.reset();good.set();
	for(int i = 0; i < (int)ps.size(); i++){
		for(ll j = a-a%i+i; j <= b; j+=i){
			good.reset(j-a);
			tested.set(j-a);
		}
		for(ll j = 1, x = ps[i]; x <= b; x*=ps[i],j++){
			if(testPrime(j)) good.set(x-a);
			else good.reset(x-a);
			tested.set(x-a);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> a >> b;
		process();
		cout << good.count() - SQN + (b-a+1) << '\n';
	}
	genPs();
}
