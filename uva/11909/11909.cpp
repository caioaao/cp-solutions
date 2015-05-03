#include <iostream>
#include <iomanip>
#include <cmath>

#define d2r(x) (x)*(pi/180.)

using namespace std;
const double pi = acos(-1.0);

int main(){
	ios_base::sync_with_stdio(false);
	
	int l, w, h, deg;
	double d, ans;
	
	while(cin >> l >> w >> h >> deg){
		d = l*tan(d2r(deg));
		
		if(d > h){
			deg = 90-deg;
			d = h*tan(d2r(deg));
			ans = d*h*w*.5;
		}
		else{
			ans = (l*(h - 0.5*d))*w;
		}
		cout << fixed << setprecision(3) << ans << " mL\n";
	}
}
