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
		int diff;
		
		vi::iterator mid = lower_bound(books.begin(), books.end(), M/2), i = mid, cmp;
		
		if(i != books.begin()){
			i--;
		
			for(; *i >= books[0]; --i){
				diff = M-*i;
				cmp = lower_bound(mid,books.end(), diff);
				if(cmp != books.end() && *cmp == diff)
					break;
			}
		}
		else{
			diff = M-*i;
			cmp = lower_bound(mid,books.end(), diff);
		}
		cout << "Peter should buy books whose prices are " << *i << " and " << *cmp << ".\n\n";
	}
}
