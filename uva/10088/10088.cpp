#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;
struct point{
	ll x, y;
	
	point(){;}
	point(ll _x, ll _y){
		x = _x;
		y = _y;
	}
};

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	ll A, B;
	point pt, anterior, primeiro;
	bool first;
	ll dx, dy;
	
	while(cin >> n, n!=0){
		first = true;
		A = 0;
		B = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> pt.x >> pt.y;
			if(first){
				primeiro = anterior = pt;
				first = false;
			}
			else{
				A += anterior.x*pt.y - pt.x*anterior.y;
				
				dx = abs(anterior.x - pt.x);
				dy = abs(anterior.y - pt.y);
				
				B += gcd(min(dx,dy), max(dx,dy)) - 1;
				
				anterior = pt;
			}
		}
		A += pt.x*primeiro.y - primeiro.x*pt.y;
		
		dx = abs(pt.x - primeiro.x);
		dy = abs(pt.y - primeiro.y);
		B += gcd(min(dx,dy), max(dx,dy)) - 1;
		
		B+=n;
		
		if(A < 0) A*=-1;
		cout << ((A - B )/2 + 1) << '\n';
	}
}
