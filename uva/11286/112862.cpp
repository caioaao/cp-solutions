#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
		int n, biggest;
		string cs, c, ci[5];
		map<string, int> rank;
		cin >> n;
		while(n != 0){
			biggest = 0;
			rank.clear();
			
			while(n--){
				for(int i = 0; i < 5; i++){
					cin >> ci[i];
				}
				sort(ci,ci+5);
				c = '\0';
				for(int i = 0; i < 5; i++){
					c = c+ci[i]; 
				}
				rank[c]++;
				biggest = max(biggest, rank[c]);
			}
			int amt = 0;
			for(map<string,int>::const_iterator i = rank.begin(); i != rank.end(); ++i){
				if(i->second == biggest)
					amt++;
			}
			cout << amt << '\n';
			cin >> n;
		}
}
