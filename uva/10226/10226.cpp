#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main(){
		ios_base::sync_with_stdio(false);
		map<string,int> trees;
		long long t, sum;
		cin >> t;
		string S;
		getline(cin, S);
		getline(cin, S);
		bool first = true;
		while(t--){
			if(!first)
				cout << '\n';
			first = false;
			sum = 0;
			trees.clear();
			
			getline(cin,S);
			while(S != "\0"){
				sum++;
				trees[S]++;
				getline(cin,S);
			}
			
			for(map<string,int>::const_iterator i = trees.begin(); i != trees.end(); ++i){
				cout << i->first << ' ';
				cout << fixed << setprecision(4)  << (100*i->second)/(double)sum << '\n';
			}
		}
}
