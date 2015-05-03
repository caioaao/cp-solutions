#include <iostream>
using namespace std;

int main(){
	for(int ii = 2; ii < 100000; ii++){
		bool prime = true;
		for(int jj = 2; jj < ii; jj++){
			if( ii%jj == 0 ){
				prime = false;
				break;
			}
		}
		if(prime){
			cout << ii << ", ";
		}
	}
}