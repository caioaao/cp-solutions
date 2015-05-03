#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define vvd vector<vector<double> >
#define vvdi vector<vector<double> >::iterator
#define vd vector<double>
#define vdi vector<double>::iterator
#define vvi vector<vector<int> >
#define vvii vector<vector<int> >::iterator
#define vi vector<int>
#define vii vector<int>::iterator

const double EPS = .001;

int p[20][20];
double edges[20][20];
double l[20][20];

void print_path(int i, int j, int begin){
	int aux = p[i][j];

	if(aux != -1){
		print_path(i, aux, begin);
		cout << aux+1 << " ";
		print_path(aux, j, begin);
	}
	
}

int main(){
	double curr;
	int dim;
	int init_l;
	
	while(!(cin >> dim).eof()){
		for(int ii = 0; ii < dim; ii++){
			for(int jj = 0; jj < dim; jj++){
				if(ii == jj){ curr = 1.; init_l = 0; }
				else { cin >> curr; init_l = 1;}

				edges[ii][jj] = curr;
				p[ii][jj] = -1;
				l[ii][jj] = init_l;
			}
		}
		int biggest_n = -1, last;
		int k = 0;
		for(; k < dim; k++){
			for(int i = 0; i < dim; i++){
				for(int j = 0; j < dim; j++){
						l[i][j]=l[i][k]+l[k][j];
						edges[i][j] = edges[i][k]*edges[k][j];
						p[i][j] = k;
					}
				}
			}
		}
		// Debug
		cout << "pesos" << endl;
		for(int ii = 0; ii < dim; ii++){
			for(int jj = 0; jj < dim; jj++){
				cout << edges[ii][jj] << ' ';
			}
			cout << endl;
		}
		cout << "pais" << endl;
		for(int ii = 0; ii < dim; ii++){
			for(int jj = 0; jj < dim; jj++){
				cout << p[ii][jj] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		// Fim debug


		bool found = false;
		for(int ii = 0; ii < dim; ii++){
			if(l[ii][ii] <= dim && edges[ii][ii] >= 1.01){
				cout << ii+1 << " ";
				print_path(ii,ii, ii);
				cout << ii+1 << endl;
				found = true; break;
			}
		}
		if(!found)
			cout << "no arbitrage sequence exists" << endl;
	}
}
