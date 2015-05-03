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
	int ma, mb, dma, dmb;

	ma = ((b.x-a.x));
	dma = ((a.y-b.y));

	mb = ((c.x-b.x));
	dmb = (b.y-c.y);

	// qa = ((a.y+b.y)*dma-ma*(a.x+b.x));
	// dqa = dma;

	int Cx, Cy, dCx, dCy;


	// bool flagx = false, flagy = false;

	// Na verdade é dividido por 2, mas assim diminui uma operacao
	
	


	if(a.y == b.y){
		dCx = 2;
		Cx = (a.x+b.x);
	}
	else if(b.y == c.y){
		dCx = 2;
		Cx = (b.x+c.x);
	}
	else if(a.y == c.y){
		dCx = 2;
		Cx = (a.x+c.x);
	}
	else{
		Cx = ((b.y*dmb-mb*b.x)*dma)-((b.y*dma-ma*b.x)*dmb);
		dCx = (ma*dmb-mb*dma);
	}

	if(a.x == b.x){
		dCy = 2;
		Cy = (a.y+b.y);
	}
	else if(b.x == c.x){
		dCy = 2;
		Cy = (b.y+c.y);
	}
	else if(a.x == c.x){
		dCy = 2;
		Cy = (a.y+c.y);
	}
	else{
		// Cy = (ma*Cx+dCx*dma*a.y-dCx*ma*a.x);
		// dCy = dma*dCx;
		Cy = a.y*a.y+a.x*a.x-b.x*b.x-b.y*b.y*dCx+2*Cx*(b.x-a.x);
		dCy = (-2*a.y + 2*b.y)*dCx;
	}

	int R, dR;

	R = -2*dCx*dCy*( dCy*Cx*a.x + dCx*Cy*a.y ) + a.x*a.x+a.y*a.y;
	// dR = dCx*dCx*dCy*dCy;
	
	int dCp, kills = 0;

	for(vp::iterator ii = positions.begin(); ii != positions.end(); ++ii){
		if(ii != ia && ii != ib && ii !=  ic){
			p = *ii;
			dCp = -2*dCx*dCy*( dCy*Cx*p.x + dCx*Cy*p.y ) + p.x*p.x+p.y*p.y;
			if(dCp <= R) kills++;
			// if(( (Cx*(p.x-a.x))*dCy+(dCx*Cy*(p.y-a.y)) ) >= dCx*dCy*(((p.x*p.x)-(a.x*a.x)+(p.y*p.y)-(a.y*a.y)))) kills++; // teste maluco de int com double
		}
	}

	// cout << ((double)Cx/dCx) << " " << ((double)Cy/dCy) << " " << kills	<< endl;

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
					// cout<< (*ii).x << " " << (*ii).y << "; " << (*jj).x << " " << (*jj).y << "; " << (*kk).x << " " << (*kk).y << endl; 
					n_morto += calc_morto(ii,jj,kk);
				}
			}
		}

		p_killed = ((double)n_morto)/(combs * ((positions.size()-3)));
		cout << setprecision(8) << p_killed << "\n";

	}
}