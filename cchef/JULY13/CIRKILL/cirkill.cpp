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

int calc_morto(vp::iterator ia, vp::iterator ib, vp::iterator ic){
	point a,b,c, p;
	a = *ia;
	b = *ib;
	c = *ic;
	// Ve se sao colineares
	int  A = abs(( ( ( a.x*b.y ) + ( a.y*c.x ) + ( b.x*c.y ) ) - ( (b.y*c.x) + (c.y*a.x) + (b.x*a.y) ) ));
	if(A == 0) return 0;

	// Encontrando retas
	line ma, mb;
	ma.m = ((double)(b.x-a.x))/((a.y-b.y));
	mb.m = ((double)(c.x-b.x))/((b.y-c.y));

	ma.q = ((a.y+b.y)-ma.m*(a.x+b.x));
	mb.q = ((b.y+c.y)-mb.m*(b.x+c.x));

	double Cx, Cy;

	// Na verdade é dividido por 2, mas assim diminui uma operacao


	Cx = (mb.q-ma.q)/(ma.m-mb.m);
	Cy = ma.m*Cx+ma.q;
	
	if(a.y == b.y)
		Cx = (a.x+b.x);
	else if(b.y == c.y)
		Cx = (b.x+c.x);
	else if(a.y == c.y)
		Cx = (a.x+c.x);



	if(a.x == b.x)
		Cy = (a.y+b.y);
	else if(b.x == c.x)
		Cy = (b.y+c.y);
	else if(a.x == c.x)
		Cy = (a.y+c.y);

	double R = ((Cx - a.x)*(Cx - a.x))+((Cy - a.y)*(Cy - a.y));
	
	int kills = 0;

	for(vp::iterator ii = positions.begin(); ii != positions.end(); ++ii){
		if(ii != ia && ii != ib && ii !=  ic){
			p = *ii;
			// if(((Cx - p.x)*(Cx - p.x))+((Cy - p.y)*(Cy - p.y)) <= R) kills++;
			// Original (tirei o 2 p compensar o 2 tirado dos Cx, Cy: if(((p.x*p.x)-(a.x*a.x)+(p.y*p.y)-(a.y*a.y)) <= 2*( (Cx*(p.x-a.x))+(Cy*(p.y-a.y)) )) kills++;
			if(((p.x*p.x)-(a.x*a.x)+(p.y*p.y)-(a.y*a.y)) <= ( (Cx*(p.x-a.x))+(Cy*(p.y-a.y)) )) kills++; // teste maluco de int com double
		}
	}
	// cout << (Cx/2) << " " << (Cy/2) << " " << kills << endl;

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