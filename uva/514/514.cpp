#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	stack<int> left, middle;
	vector<int> right;
	int N, vagao, vagaol, vagaom;
	string line; stringstream buffer;
	cin >> N;
	getline(cin, line);
	
	bool firstCase = true;
	
	while(N != 0){
		getline(cin, line);
		while(line != "0"){
			right.clear();
			buffer.str(line);
			
			for(int i = 0; i < N; i++){
				buffer >> vagao;
				left.push(vagao);
			}
			buffer.clear();
			
			while(!middle.empty() || !left.empty()){
				if(middle.empty()){
					middle.push(left.top()); left.pop();
					continue;
				}if(left.empty()){
					right.push_back(middle.top()); middle.pop();
					continue;
				}
				vagaol = left.top();
				vagaom = middle.top();
				if(vagaom > vagaol){
					right.push_back(vagaom); middle.pop();
				}
				else{
					middle.push(vagaol); left.pop();
				}
			}
			
			bool correct = true;
			
			for(int i = 0; i < N; i++){
				if(right[i] != N-i){
					correct = false; break;
				}
			}
			if(correct)
				cout << "Yes\n";
			else
				cout << "No\n";
			
			getline(cin,line);
		}
		cout << '\n';
		cin >> N;
		getline(cin, line);
	}
	
}
