#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
map<ll,vi> memo;



inline vi count(ll d){
	vi digits(10,0);
	int digit;
	for(int i = 1; i <= d ; i*=10){
		digit = (int)(d/i)-((int)(d/(i*10)))*10;
		digits[digit]++;
	}
	return digits;
}

vi amt(ll d){
	if(d == 0) return vi(10, 0);
	if(memo.count(d)) return memo[d];
	vi esse = count(d), nxt = amt(d-1);
	for(int i = 0; i < 10; i++){
		esse[i] += nxt[i];
	}
	return (memo[d] = esse);
}

int main(){
	ios_base::sync_with_stdio(false);
	ll N, d;
	cin >> N;
	while(N--){
		cin >> d;
		vi digits = amt(d);
		cout << digits[0];
		for(int i =1; i <10; i++){
			cout << ' ' << digits[i];
		}
		cout << '\n';
	}
	
}
