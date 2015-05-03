#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T, h1,m1,h2,m2, dist;
	char sep;
	cin >> T;
	while(T--){
		cin >> h1 >> sep >> m1 >> h2 >> sep >> m2 >> dist;
		//~ cout << h1 << ' ' << m1 << ' ' << h2 << ' ' << m2 << endl;
		m1 += h1*60;
		m2 += h2*60;
		double c1 = m1 + dist - m2;
		double c2 = max(m1 + ((m2-m1+2*dist)/2.0), (double)m1) - m2;
		cout << fixed << setprecision(1) << c1 << ' ' << c2 << '\n';
	}
}
