#include<iostream>

int main(){
	long long d = 1;
	long long ans = 1;
	for(long long i = 1; i <= 10000000000000000ll; i++){
		ans = (ans*2)%1000000007;
		if(i == d) {
			std::cout << ans;
			d = (d*10);
			
		}
	}
}
