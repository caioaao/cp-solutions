#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int cards[13][4], cSuits[4], suitsC[4][5], points, su, nStopped;
	string s;
	char card,suit;
	stringstream buff;
	while(getline(cin, s)){
		memset(cards, 0, sizeof cards);
		memset(cSuits, 0, sizeof cSuits);
		memset(suitsC, 0, sizeof suitsC);
		points = 0;nStopped = 0;

		buff.clear(); buff.str(s);
		while(buff >> card >> suit){
			if(suit == 'S') su = 0;
			if(suit == 'H') su = 1;
			if(suit == 'D') su = 2;
			if(suit == 'C') su = 3;
			
			cSuits[su]++;
			
			if(card == 'A') {
				points += 4;
				suitsC[su][0]++;
			}
			else if(card == 'J'){
				points += 1;
				suitsC[su][3]++;
			}
			else if(card == 'Q'){
				points += 2;
				suitsC[su][2]++;
			}
			else if(card == 'K'){
				points += 3;
				suitsC[su][1]++;
			}
			else suitsC[su][4]++;
			
			
		}
		
		int more = 0, mI = -1;
		
		for(int i = 0; i < 4; i++){
			if(suitsC[i][0] > 0 || (suitsC[i][1] > 0 && cSuits[i] > 1 ) || ( suitsC[i][2] && cSuits[i] > 2 ) ){
				nStopped++;
			}
			if(cSuits[i] > more){
				more = cSuits[i];
				mI = i;
			}
			if(suitsC[i][1] > 0 && cSuits[i] == 1) points--; 
			if(suitsC[i][2] > 0 && cSuits[i] <= 2) points--;
			if(suitsC[i][3] > 0 && cSuits[i] <= 3) points--;
		}
		
		if(points >= 16 && nStopped == 4){
			cout << "BID NO-TRUMP\n";
			continue;
		}
		for(int i = 0; i < 4; i++){
			if(cSuits[i] == 2) points++;
			else if(cSuits[i] == 1) points+=2;
			else if(cSuits[i] == 0) points+=2;
		}
		if(points >= 14){
			if(mI == 0) suit = 'S';
			if(mI == 1) suit = 'H';
			if(mI == 2) suit = 'D';
			if(mI == 3) suit = 'C';
			cout << "BID " << suit << '\n';
		}
		else cout << "PASS\n";
	}
}
