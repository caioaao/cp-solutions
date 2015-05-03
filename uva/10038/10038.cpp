#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
bool sq[3001];
int main(){
		int n, it, last;
		while(cin >> n){
			memset(sq, 0, sizeof(sq));
			for (int i = 0; i < n; i++){
					cin >> it;
					if(abs(last-it) < n)
						sq[abs(last-it)] = true;
					last = it;
			}
			bool hasIt = true;
			for(int i = 1; i < n; i++){
					if(!sq[i]){
							hasIt = false;
							break;
					}
			}
			cout << ((hasIt) ? "Jolly\n":"Not jolly\n" ); 
		}
}
