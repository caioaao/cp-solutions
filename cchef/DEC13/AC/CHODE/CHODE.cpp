#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;
typedef pair<int,char> pic;

vector<pic> freq;

int isUpper(char c){
	for(char teste = 'A'; teste <= 'Z'; teste++){
		if(c == teste)
			return c-'A';
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int T; 
	string order, orig;
	stringstream buffer;
	map<char,char> transl;
	cin >> T;
	while(T--){
		transl.clear();
		freq.assign(26, pic(0, '\0'));
		for(char c = 'a'; c <= 'z'; c++) freq[c-'a'].second = c; 
		
		cin >> order;
		getline(cin, orig);
		getline(cin, orig);
		int ind;
		for(int i = 0; i < (int)orig.length(); i++){
			ind = orig[i]-'a';
			if(ind < 0 || ind >= 26) ind = isUpper(orig[i]);
			if(ind >= 0) freq[ind].first++;
		}
		sort(freq.begin(), freq.end());
		
		for(int i = 0; i < (int)freq.size(); i++) transl[freq[i].second] = order[i];
		for(int i = 0; i < (int)orig.length(); i++){
			char c = orig[i];
			//~ cout << c;
			if( c- 'a' >= 0 && c - 'a' < 26){
				orig[i] = transl[c];
			}
			else if( c - 'A' >= 0 && c - 'A' < 26 ){
				orig[i] = toupper(transl[tolower(c)]);
			}
		}
		cout << orig << '\n';
	}
}
