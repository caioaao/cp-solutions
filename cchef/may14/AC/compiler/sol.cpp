#include <iostream>
#include <string>
#include <stack>
#include <utility>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	ll T;
	cin >> T;
	string s;
	while(T--){
		cin >> s;
		
		stack<int> stack;
		int ans = 0;
		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] == '<') stack.push(i);
			else{
				if(stack.size() > 0){
					stack.pop();
					if(stack.size() == 0) ans = i+1;
				}
				else{
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}
