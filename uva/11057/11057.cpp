#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

vi books;

int main(){
	int N, M, bk;
	while(cin >> N){
		books.clear();
		for(int i = 0; i < N; i++){
			cin >> bk;
			books.push_back(bk);
		}
		sort(books.begin(), books.end());
		
		cin >> M;
		bool found = false;
		int i = M/2;
		vi::iterator ii, jj;
		while(!found && i >=0){
			ii = lower_bound(books.begin(), books.end(), i);
			jj = upper_bound(ii+1, books.end(), M-i)-1;
			//cout << (int)(jj-books.begin()) << ',' << *ii << ',' << *jj << endl;
			if( ii != books.end() && jj != books.end() && *ii+*jj == M && ii != jj)
				break;
			i--;
		}
		
		cout << "Peter should buy books whose prices are " << i << " and " << M-i << ".\n\n";
	}
}
