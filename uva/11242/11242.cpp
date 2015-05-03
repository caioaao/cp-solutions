#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct fraction{
	int N, D;
	
	fraction(int _n, int _d){
		N = _n; D = _d;
	}
};

bool is_bigger(fraction a, fraction b){
	return a.N*b.D > b.N*a.D;
}
bool is_smaller(fraction a, fraction b){
	return a.N*b.D < b.N*a.D;
}

fraction sum(fraction a, fraction b){
	int n = a.N*b.D+b.N*a.D;
	int d = a.D*b.D;
	return fraction(n,d);
}

fraction divide(fraction a, fraction b){
	int n = a.N*b.D;
	int d = a.D*b.N;
	return fraction(n,d);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int f, r, fs[11], rs;
	vector<fraction> ds;
	
	cin >> f;
	while(f != 0){
		cin >> r;
		ds.clear();
		
		for(int i = 0; i < f; i++){
			cin >> fs[i];
		}
		for(int i = 0; i < r; i++){
			cin >> rs;
			for(int j = 0; j < f; j++){
				ds.push_back(fraction(fs[j],rs));
			}
		}
		
		sort(ds.begin(), ds.end(), is_smaller);
		
		fraction bigger(0,1), div(0,1);
		for(vector<fraction>::iterator it = ds.begin()+1; it != ds.end(); ++it){
		//	cout << it->N/(double)it->D << '\n';
			div = divide(*it, *(it-1));
			
			if(is_bigger(div,bigger)) bigger = div;
		}
		cout << fixed << setprecision(2) << bigger.N/(double)bigger.D << '\n';
		cin >> f;
	}
}
