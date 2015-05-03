#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point{
	int x, y;
	point(){;}
};

int n, inds[10], best[10];
point pts[10];

void copy(int *a, int *b){
	for(int i = 0; i < n; i++){
		b[i] = a[i];
	}
}

int dist2(point a, point b){return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);}

double feval(int *path){
	double ret = 0;
	for(int i = 0; i < n-1; i++){
		ret += sqrt(dist2(pts[path[i]],pts[path[i+1]]));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int net = 1;
	while(cin >> n, n!=0){
		for(int i = 0; i < n; i++){
			cin >> pts[i].x >> pts[i].y;
			inds[i] = i;
		}
		double v_best = feval(inds), aux;
		copy(inds,best);
		while(next_permutation(inds, inds+n)){
			aux = feval(inds);
			if(aux < v_best){
				v_best = aux;
				copy(inds,best);
			}
		}
		cout << "**********************************************************\n";
		cout << "Network #" << net++ << '\n';
		double aux_d, tot = 0;
		for(int i = 0; i < n - 1; i++)
		{
			aux_d = sqrt(dist2(pts[best[i]], pts[best[i+1]])) + 16;
			
			cout << "Cable requirement to connect (" << pts[best[i]].x << ',' << pts[best[i]].y << ") to (" << pts[best[i+1]].x << ',' << pts[best[i+1]].y << ") is ";
			cout << fixed << setprecision(2) << aux_d;
			cout << " feet.\n";
			tot += aux_d;
		}
		cout << "Number of feet of cable required is " << fixed << setprecision(2) << tot << ".\n";
		
	}
}
