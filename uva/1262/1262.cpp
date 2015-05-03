#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, g1[5], g2[5], gf[5], nth;
char C;
vector<string> poss;
void generate(int id, string s){
	if((int)poss.size() >= nth)
		return ;
	if(id == 5){
		poss.push_back(s);
		return ;
	}
	string ns = s;
	for(int i = 0; i < 26; i++){
		if((gf[id] & (1 << i)) != 0){
			ns[id] = i+'A';
			generate(id+1,ns);
		}
	}
	
}

inline int numOfSetBits(int i){ //só pra int de 32 bits
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(){
	cin >> T;
	
	while(T--){
		poss.clear();
		memset(g1, 0, sizeof g1);
		memset(g2, 0, sizeof g2);
		memset(gf, 0, sizeof gf);
		
		
		cin >> nth;
		
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				cin >> C;
				g1[j] |= (1 << (C-'A'));
			}
		}
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				cin >> C;
				g2[j] |= (1 << (C-'A'));
			}
		}
		int nPoss = 1;
		for(int i = 0; i < 5; i++){
			gf[i] = g1[i] & g2[i];
			nPoss*=numOfSetBits(gf[i]);
		}
		if(nPoss < nth){
			cout << "NO\n";
			continue;
		}
		
		generate(0,string(5, ' '));
		if((int)poss.size() < nth){
			cout << "NO\n";
			continue;
		}
		cout << poss[nth-1] << '\n';
		
	}
}
