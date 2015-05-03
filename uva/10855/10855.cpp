#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	
	int nb, ns;
	string dummy;
	ll n0, n90, n180, n270;
	vector<string> big, small;
	cin >> nb >> ns;
	while(nb != 0){
		n0 = n90 = n180 = n270 = 0;
		big.assign(nb, "");
		small.assign(ns, "");
		
		
		getline(cin,dummy);
		for(int i = 0; i < nb; i++)
			getline(cin,big[i]);
			
		for(int i = 0; i < ns; i++){
			getline(cin,small[i]);
		}
		/*
		for(int i = 0; i < ns; i++){		
			for(int j = 0; j < ns; j++){
				cout << small[i][j] << ' ';
			}	
			cout << endl;
		}
			cout << endl;
		for(int i = 0; i < ns; i++){		
			for(int j = 0; j < ns; j++){
				cout << small[ns-j-1][i] << ' ';
			}	
			cout << endl;
		}
			cout << endl;
		for(int i = 0; i < ns; i++){		
			for(int j = 0; j < ns; j++){
				cout << small[ns-i-1][ns-j-1] << ' ';
			}	
			cout << endl;
		}
			cout << endl;
		for(int i = 0; i < ns; i++){		
			for(int j = 0; j < ns; j++){
				cout << small[j][ns-i-1] << ' ';
			}	
			cout << endl;
		}
		*/
		bool f0 = true, f90 = true, f180 = true, f270 = true;
		for(int kr = 0; kr < nb-ns+1; kr++){ // start
			for(int kc = 0; kc < nb-ns+1; kc++){ // start
				f0 = f90 = f180 = f270 = true;
				for(int i = 0; i < ns; i++){
					for(int j = 0; j < ns; j++){
						if(small[i][j] != big[i+kr][j+kc]) f0 = false;
						if(small[ns-j-1][i] != big[i+kr][j+kc]) f90 = false;
						if(small[ns-i-1][ns-j-1] != big[i+kr][j+kc]) f180 = false;
						if(small[j][ns-i-1] != big[i+kr][j+kc]) f270 = false;
					}
				}
				if(f0) n0++;
				if(f90) n90++;
				if(f180) n180++;
				if(f270) n270++;
			}
		}
		
		cout << n0 << ' ' << n90 << ' ' << n180 << ' ' << n270 << '\n';
		
		cin >> nb >> ns;
	}
}
