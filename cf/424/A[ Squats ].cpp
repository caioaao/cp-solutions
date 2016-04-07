#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>


using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	while(cin >> n){
		string str;
		cin >> str;
		int amtS = 0;
		for(int i = 0; i < n; i++){
			if(str[i] == &#39;X&#39;) amtS++;
		}
		cout << abs((n/2)-amtS) << &#39;\n&#39;;
		for(int i = 0; i < n; i++){
			if(amtS < n/2){
				cout << &#39;X&#39;;
				if(str[i] == &#39;x&#39;) amtS++;
			}
			else if(amtS > n/2){
				cout << &#39;x&#39;;
				if(str[i] == &#39;X&#39;) amtS--;
			}
			else cout << str[i];
		}
		cout << &#39;\n&#39;;
	}
}
