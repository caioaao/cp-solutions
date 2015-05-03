	#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;
#define vpi vector<point>::iterator
#define inf numeric_limits<double>::infinity()

const double EPS = .0000001;

struct point{
	double x,y;
};

struct line{
	double m, q;
};

struct circle{
	double rsq;
	point center;
	int kill;
	// bool deu;
};

vector<point> pos;

double seuclid_dist(point a, point b){
	return ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
}

int find_circle(vpi aa, vpi ab, vpi ac){
	point a = *aa;
	point b = *ab;
	point c = *ac;
	circle circulo;
	// Testando e achando area de triangulo (ja usa p encontrar raio de circ.)
	double A = fabs(( 1./2. ) * ( ( ( a.x*b.y ) + ( a.y*c.x ) + ( b.x*c.y ) ) - ( (b.y*c.x) + (c.y*a.x) + (b.x*a.y) ) ));

	if( A <= EPS ){
		// circulo.deu = false;
		return -1;
	}
	else{
		// Encontrando circuncentro. Apesar de ser a intersecao das tres mediatrizes do triangulo, pode-se usar 2 (duas retas se cruzam em so um ponto)

		line ma, mb;
		point C;


		ma.m = -(a.x-b.x)/(a.y-b.y);
		mb.m = -(b.x-c.x)/(b.y-c.y);

		ma.q = ((a.y+b.y)/2.)-ma.m*((a.x+b.x)/2.);
		mb.q = ((b.y+c.y)/2.)-mb.m*((b.x+c.x)/2.);

		// printf("Linha a: %lfx+ %lf\n", ma.m,ma.q);
		// printf("Linha b: %lfx+ %lf\n\n", mb.m,mb.q);

		C.x = (mb.q-ma.q)/(ma.m-mb.m);
		C.y = ma.m*C.x+ma.q;

		if(fabs(a.x - b.x) < EPS)
			C.y = (a.y+b.y)/2.;
		else if(fabs(b.x - c.x) < EPS)
			C.y = (b.y+c.y)/2.;

		if(fabs(a.y- b.y) < EPS)
			C.x = (a.x+b.x)/2.;
		else if(fabs(b.y - c.y) < EPS)
			C.x = (b.x+c.x)/2.;
		
		circulo.center = C;
		circulo.rsq = seuclid_dist(C,a);

		cout << C.x << " " << C.y << endl;

		if(circulo.rsq == inf && C.x != inf && C.y != inf)
			return pos.size()-3;

		circulo.kill = 0;
		for(vpi ii = pos.begin(); ii != pos.end(); ++ii){
			if(( ii != aa && ii != ab && ii != ac) && seuclid_dist(*ii,C) <= circulo.rsq){
				circulo.kill++;
			}
		}


		// Debug
		// if(C.x != C.x || C.y != C.y){
			// printf("A: %f %f; B:  %f %f;C  %f %f;\n\n",a.x,a.y,b.x,b.y,c.x,c.y);
		// printf("C: %f %f\n\n", C.x, C.y);
		// }
	}
	return circulo.kill;
}

int main(){
	int t, n, x, y, soma_p, teste, n_circulos;
	double p_killed;
	point xy;
	circle circ;
	scanf("%d\n",&t);

	while(t--){
		pos.clear();
		scanf("%d\n", &n);

		int n_arrangements = (n*(n-1)*(n-2))/6;
		int last = n - 3;
		while(n--){
			scanf("%d %d\n", &x, &y);
			xy.x = (double)x;
			xy.y = (double)y;
			pos.push_back(xy);
		}

		soma_p = 0;
		n_circulos = 0;
		for(vpi ii = pos.begin(); ii != pos.end(); ++ ii){
			for(vpi jj = ii+1; jj != pos.end(); ++jj){
				for(vpi zz = jj+1; zz != pos.end(); ++zz){

					teste=find_circle(ii,jj,zz);
					if(teste >= 0 ){
						soma_p+=teste;
						n_circulos++;
					}
					// circ=find_circle(ii,jj,zz);
					// if(circ.deu){
					// 	soma_p += circ.kill;
					// }
				}
			}
		}


		// printf("%d\n",soma_p);
		p_killed = (( (double)soma_p)/ ((double)n_arrangements *(double) (pos.size() - 3)));
		cout << setprecision(8) << p_killed << endl;
		// printf("%.8f\n",p_killed);
	//	printf("%lf\n",soma_p/((double)n_arrangements));
	}
}