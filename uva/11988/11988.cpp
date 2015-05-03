#include <iostream>
#include <list>

using namespace std;

list<char> lst;

int main(){
	ios_base::sync_with_stdio(false);
	
	string line;
	while(getline(cin,line)){
		lst.clear();
		list<char>::iterator it = lst.begin();
		for(int i = 0; i < (int)line.size(); i++){
			if(line[i] == '[') it = lst.begin();
			else if(line[i] == ']') it = lst.end();
			else lst.insert(it,line[i]);
		}
		
		for(it = lst.begin(); it != lst.end(); ++it) cout << *it;
		cout << '\n';
	}
}
