#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int xd, yd, amtL, amtR, dL, dR;

string strL, strR;

bool between(int i1, int i2, int x){
	int l = min(i1,i2), r = max(i1,i2);
	if(x >= l && x <= r) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	int T, N, amt;
	string s, d;
	stringstream buffer;
	cin >> T;
	while(T--){
		cin >> N;
		amt = 0;
		buffer.clear();
		buffer.str("");
		int x, y, ops;
		cin >> x >> y;
		for(int it = 1; it < N; it++){
			cin >> xd >> yd;
			
			ops = abs(x - xd) + abs(y - yd);
			amt += ops;
			
			
			strL = (x > xd ? "L-" : "L+");
			strR = (y > yd ? "R-" : "R+");
			
			dL = (x > xd ? -1 : 1);
			dR = (y > yd ? -1 : 1);
			
			if(xd == x && yd == y) continue;
			if(y <= xd){
				for(; x < y-1; x++)
					buffer << strL;
				x = y-1;
				for(; y < xd+1; y++){
					buffer << strR;
					if(x < xd){
						x++;
						buffer << strL;
					}
				}
				y = xd+1;
				for(; y < yd; y++)
					buffer << strR;
					
				x = xd; y = yd; continue;
			}
			else{
				for(int i = 0; i < abs(x-xd); i++)
						buffer << strL;
				for(int i = 0; i < abs(y-yd); i++)
						buffer << strR;
			}
			
			x = xd; y = yd;
		}
		getline(buffer, s);
		cout << amt << '\n' << s << '\n';
	}
}
