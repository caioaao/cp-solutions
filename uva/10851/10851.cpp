#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string linhas[8];
char vals[256][8];

char findChar(int j){
	int ans;
	
	bool wrong;
	for(int i = 0; i < 256; i++){
		wrong = false;
		for(int k = 0; k < 8; k++){
			if(linhas[k][j] != vals[i][k]){
				 wrong = true;
				 break;
			 }
		}
		if(!wrong){
			ans = i;
			break;
		}
	}
	
	return (char)ans;
}

void preprocess(){
	for(int i = 0; i < 256; i++){
		//~ cout << (char) i << ':';
		for(int pot = 1, j = 0 ; j < 8; j++, pot*=2){
			if((i/pot)%2 == 0) vals[i][j] = '/';
			else vals[i][j] = '\\';
			//~ cout << vals[i][j];
		}
		//~ cout << endl;
	}
	//~ cout << endl << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	preprocess();
	while(n--){
		getline(cin, linhas[0]);
		getline(cin, linhas[0]);
		
		for(int i = 0; i < 8; i++) getline(cin,linhas[i]);
		//~ for(int i = 0; i < 8; i++) cout << linhas[i] << endl;
		
		for(int j = 1; j < (int)linhas[0].length()-1; j++)
			cout << findChar(j);
		cout << '\n';
		getline(cin, linhas[0]);
	}
}
