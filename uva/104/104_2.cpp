#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

#define EPS 1e-9

using namespace std;

#define vvd vector<vector<double> >
#define vvdi vector<vector<double> >::iterator
#define vd vector<double>
#define vdi vector<double>::iterator
#define vvi vector<vector<int> >
#define vvii vector<vector<int> >::iterator
#define vi vector<int>
#define vii vector<int>::iterator
#define INF numeric_limits<int>::infinity()
#define INFd numeric_limits<double>::infinity()

int p[20][20];
double edges[20][20];
double l[20][20];

void print_path(int i, int j){
	if(i != j)
		print_path(i,p[i][j]);
	cout << j+1 << " ";
	
}

int main(){
	double curr;
	int dim;
	int init_p;
	
	while(!(cin >> dim).eof()){
		for(int ii = 0; ii < dim; ii++){
			for(int jj = 0; jj < dim; jj++){
				if(ii == jj){
					curr = 0;
				}
				else {
					cin >> curr;
					curr = -log(curr);
				}

				edges[ii][jj] = curr;
				p[ii][jj] = ii;
				l[ii][jj] = (ii == jj ) ? 0 : 1;
			}
		}
		int biggest_n = -1, last;
		int k = 0;
		for(k=0; k < dim; k++){
			for(int i = 0; i < dim; i++){
				for(int j = 0; j < dim; j++){
					if(edges[i][k]+edges[k][j] < edges[i][j]){
						l[i][j]=l[i][k]+l[k][j];
						edges[i][j] = edges[i][k]+edges[k][j];
						p[i][j] = p[k][j];
					}
				}
			}
		}

		// Debug
//		cout << "pesos" << endl;
//		for(int ii = 0; ii < dim; ii++){
//			for(int jj = 0; jj < dim; jj++){
//				cout << edges[ii][jj] << ' ';
//			}
//			cout << endl;
//		}
//		cout << "pais" << endl;
//		for(int ii = 0; ii < dim; ii++){
//			for(int jj = 0; jj < dim; jj++){
//				cout << p[ii][jj] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;
//		cout << "l" << endl;
//		for(int ii = 0; ii < dim; ii++){
//			for(int jj = 0; jj < dim; jj++){
//				cout << l[ii][jj] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;
		// Fim debug


		bool found = (edges[0][0] < 0) ? true : false;
		int min = l[0][0], min_ind = 0;

		for(int ii = 0; ii < dim; ii++){
			if(edges[ii][ii] < -log(1.01) && l[ii][ii] < min){
				min_ind = ii;
				min = l[ii][ii];
				found = true;
			}
		}
		if(!found)
			cout << "no arbitrage sequence exists";
		else{
			print_path(min_ind,p[min_ind][min_ind]);
			cout << min_ind+1 << ' ';
		}
		cout << endl;
	}
}
