#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, x1,y1,x2,y2,x3,y3, smallest = INF, biggest = 0, s, sI, bI;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		s = abs(x1*y2+x3*y1+x2*y3 - ( x3*y2+x1*y3+x2*y1 ));
		if(s >= biggest){
			bI = i; biggest = s;
		}
		if(s <= smallest){
			sI = i; smallest = s;
		}
	}
	cout << sI << ' ' << bI;
}
