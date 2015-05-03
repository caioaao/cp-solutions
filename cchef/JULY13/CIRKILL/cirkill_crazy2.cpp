#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>

#define vp vector<point>

using namespace std;

const double EPS = 0.0000001;

struct point{
	int x, y;
};

struct line{
	double m, q;
};

vp positions;

int euc_dist(point a, point b){
	return ((a.x-b.x)*(a.x - b.x)+(a.y-b.y)*(a.y-b.y));
}

int calc_morto(vp::iterator ia, vp::iterator ib, vp::iterator ic){
	point a,b,c, p;
	a = *ia;
	b = *ib;
	c = *ic;
	// Ve se sao colineares
	int  A = abs(( ( ( a.x*b.y ) + ( a.y*c.x ) + ( b.x*c.y ) ) - ( (b.y*c.x) + (c.y*a.x) + (b.x*a.y) ) ));
	if(A == 0) return 0;

	int pa, pb, pc, ab = euc_dist(a,b), bc = euc_dist(b,c), ca = euc_dist(c,a);
	int R = ab*bc*ca;

	int kills = 0;

	for(vp::iterator ii = positions.begin(); ii != positions.end(); ++ii){
		if(ii != ia && ii != ib && ii !=  ic){
			p = *ii;
			pa = euc_dist(p,a)*A*A*4;
			pb = euc_dist(p,b)*A*A*4;
			pc = euc_dist(p,c)*A*A*4;

			if(pa <= R*R && pb <= R*R && pc <= R*R)
				kills++;
		}
	}

	return kills;
}

int main(){
	int N, n_ind, t, combs, n_morto;
	point input;
	double p_killed;

	cin >> t;
	while(t--){
		cin >> n_ind;

		N = n_ind;
		combs = (N*(N-1)*(N-2))/6;

		positions.clear();

		while(n_ind--){
			cin >> input.x >> input.y;

			positions.push_back(input);
		}

		n_morto = 0;

		for(vp::iterator ii = positions.begin(); ii != positions.end(); ++ii){
			for(vp::iterator jj = ii+1; jj != positions.end(); ++jj){
				for(vp::iterator kk = jj+1; kk != positions.end(); ++kk){
					n_morto += calc_morto(ii,jj,kk);
				}
			}
		}

		p_killed = ((double)n_morto)/(combs * ((positions.size()-3)));
		cout << setprecision(8) << p_killed << "\n";

	}
}