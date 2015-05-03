#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define INF 1e9

using namespace std;

vector <string> arrangements;
int diagr, diagl, r, pos[8], amt = 0;

void generate(int diagl, int diagr, int r, int c, string s){
	if(c == 8){ arrangements.push_back(s); amt++; return ; }
	for(int i = 0; i < 8; i++){
		if((r & (1<<i)) == 0){
			int dl, dr;
			dl = c-i+7;
			dr = c-(7-i)+7;
			if(((diagl &(1<<dl)) == 0) && (diagr & ( 1 << dr )) == 0){
				string s2 = s;
				s2[c] = i+'0';
				generate(diagl | (1 << dl), diagr | (1 << dr), r |( 1<< i), c+1, s2);
			}
		}
	}
	return ;
}

int main(){
	generate(0,0,0,0, string("........"));
	
	string line; stringstream buffer;
	//for(int i = 0; i < (int)arrangements.size(); i++) cout << arrangements[i] << '\n';
	//cout << amt << ' ';
	int caso = 1;
	while(getline(cin,line)){
		buffer.clear();
		buffer.str(line);
		for(int i = 0; i < 8; i++){
			buffer >> pos[i];
			pos[i]--;
		}
		int ans = INF, s;
		for(int i = 0; i < (int)arrangements.size(); i++){
			s = 0;
			for(int j = 0; j < 8; j++){
				s += (arrangements[i][j] == pos[j]+'0' ? 0 : 1);
			}
			
			ans = min(ans,s);
		}
		cout<< "Case " << caso++ << ": " << ans << '\n';
	}
}
