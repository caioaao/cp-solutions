#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main(){
	ios_base::sync_with_stdio(false);
	
	int a,b,c;
	double s, perim, triang, incirc, circumcirc;
	while(cin >> a >> b >> c){
		perim = (a + b + c);
		s = perim*.5;
		
		triang = sqrt(s*(s-a)*(s-b)*(s-c));
		
		incirc = pi * (triang / s) * (triang / s);
		
		circumcirc = (a*b*c) / (4.0*triang); // radius
		circumcirc = pi * circumcirc * circumcirc;
		
		cout << fixed << setprecision(4) << circumcirc - triang << ' ' << triang - incirc << ' ' << incirc << '\n';
	}
}
