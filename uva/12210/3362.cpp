#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
	int B,S, ageS, ageB, age_s;
	int indice = 1;
	cin >> B >> S;
	while(B != 0 && S != 0){
		cout << "Case " << indice << ": ";
		if(S >= B){
			for(int i = 0; i < B; i++){
				cin >> ageS;
			}
			for(int i = 0; i < S; i++){
				cin >> ageS;
			}
			cout << "0";
		}else{
			age_s = 70;
			for(int i = 0; i < B; i++){
				cin >> ageB;
				age_s = min(ageB,age_s);
			}
			for(int i = 0; i < S; i++){
				cin >> ageS;
			}
			cout << B-S << " " << age_s;
		}
		indice++;

		cout << endl;

		cin >> B >> S;
	}
}
