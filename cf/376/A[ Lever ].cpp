#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	while(cin >> s){
		int pivot;
		for(int i = 0; i < (int)s.length(); i++)
			if(s[i] == &#39;^&#39;){
				pivot = i;
				break;
			}
		long long momentum = 0;
		for(int i = 0; i < pivot; i++){
			momentum+= (pivot - i) * (s[i] == &#39;=&#39; ? 0 : s[i]-&#39;0&#39;);
		}
		for(int i = pivot+1; i < (int)s.length(); i++){
			momentum -= (i - pivot) * (s[i] == &#39;=&#39; ? 0 : s[i]-&#39;0&#39;);
		}
		if(momentum == 0)
			cout << "balance\n";
		else if(momentum < 0)
			cout << "right\n";
		else
			cout << "left\n";
	}
}
