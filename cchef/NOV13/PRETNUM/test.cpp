#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;
bitset<1000000> bs;
vector<ll> ps;

inline ll nDivs(ll num){
	ll PF, divs = 1;
	for(int i = 0; i <(int)ps.size() && ps[i] <= sqrt(num); i++){
		if(num%ps[i] == 0){
			PF = 1;
			while(num%ps[i] == 0){
				PF++; num/=ps[i];
			}
			divs *= PF;
			if(num < 1000000 && bs.test(num)){
				return divs + 1;
			}
		}
	}
	return divs;
}


inline void genPs(){
	bs.set();
	bs.reset(0); bs.reset(1);
	for(int i = 2; i< 1000000; i++){
		if(bs.test(i)){
			ps.push_back(i);
			for(int j = i+i; j < 1000000; j+=i) bs.reset(j);
		}
	}
}



int main(){
	genPs();
	int amt = 0, amtC = 0;
	for(int i = 5; i < 1000000; i*=i*i){
		amtC++;
		if(bs.test(nDivs(i))) amt++; //cout << i << ',' << nDivs(i) << endl;
	}
	cout << amt << '.'<< amtC;
}
