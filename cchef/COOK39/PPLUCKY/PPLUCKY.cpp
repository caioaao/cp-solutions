#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int T, N;
	string line;
	vector<string> nstr;
	cin >> T;
	
	while(T--){
		cin >> N;
		getline(cin,line);
		getline(cin,line);
		
		nstr.clear();
		
		int begin, end = 0, last = 0;
		while((begin = line.find("47",last)) != string::npos){
			cout << "Begin:" << begin << endl;
			end = begin+1;
			while((begin-1 >= 0 && line[begin-1] == '4') &&(end+1 < N && line[end+1]=='7')){
				begin--; end++;
			}
			cout << last << ',' << begin << ':' << end << ' ';
			if(begin != last){
				nstr.push_back(line.substr(last,begin-last));
			}
			cout << line <<',';
			last = end+1;
		}
		for(vector<string>::iterator s = nstr.begin(); s != nstr.end(); ++s){
			cout << (*s);
		}
		if(end != N-1)
			cout << line.substr(end, N-end) << '\n';
	}
}
