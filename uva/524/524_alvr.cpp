#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, n;
vector<int> primevec;
vector<vector<int> > res;

int isprime(int s) {
	return binary_search(primevec.begin(), primevec.end(),s);
}

void generate(vector<int> seq, int mask) {

	if (seq.size() == n-2) {
		int last = seq[seq.size()-1], rem;
		for (int i=0; i<n-1; i++) {
			if ((mask & (1 << i)) != 0) {
				rem = i+2;
				if (isprime(rem+last) && isprime(rem+1)) {
					seq.push_back(rem);
					res.push_back(seq);
				}
				break;
			}
		}
		return;
	}

	if (seq.empty()) {
		for (int i=0; i<n-1; i++) {
			int num = i+2;
			if (isprime(1+num)) {
				vector<int> novo;
				novo.push_back(num);
				generate(novo, mask & ~(1 << i));
			}
		}
		return;
	}

	int last = seq[seq.size()-1], num;	
	for (int i=0; i<n-1; i++) {
		if ((mask & (1 << i)) != 0) {
			num = i+2;
			if (isprime(num+last)) {
				vector<int> novo;
				novo.insert(novo.begin(), seq.begin(), seq.end());
				novo.push_back(num);

				generate(novo, mask & ~(1 << i));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	primevec.reserve(11);
	int caso = 0;

	for (int i=0; i<11; i++)
		primevec.push_back(primes[i]);

	while (cin >> n) {
		vector<int> empty;
		res.clear();

		cout << "Case " << ++caso << ":" << "\n";
		
		generate(empty, ~0);
		for (int i=0; i<res.size(); i++) {
			cout << "1";
			for (int j=0; j<res[i].size(); j++)
				cout << " " << res[i][j];
			cout << "\n";
		}
		cout << "\n";
	}
}
