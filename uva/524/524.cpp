#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef map<int, set<int> > mivi;

int N;
mivi somas;

bool isPrime(int p){
	if(p%2 == 0) return false;
	for(int i = 3; i <= sqrt(p); i+=2){
		if(p%i == 0) return false;
	}
	return true;
}

vector<string> poss;

void generate(int id, int amt, string s, int avail){
	if(amt == N-1 && somas[0].count(id)){
		string s2 = s; s2[amt] = id+1+'0'; poss.push_back(s2);
	}
	string s2 = s;
	s2[amt] = id+1+'0';
	avail |= 1 << id;
	for(set<int>::iterator it = somas[id].begin(); it != somas[id].end(); ++it){
		if((avail & (1 << *it)) == 0)
			generate((*it), amt+1, s2, avail | (1<< (*it)));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int caso = 1;
	bool first = true;
	while(cin >> N){
		if(!first) cout << '\n';
		first = false;
		cout << "Case " << caso++ << ":\n";
		somas.clear();
		poss.clear();
		
		for(int i = 1; i <= N; i++){
			for(int j = 1; j < i; j++){
				if(isPrime(i+j)){
					somas[i-1].insert(j-1);
					somas[j-1].insert(i-1);
				}
			}
		}
		generate(0, 0, string(N,' '), 0);
		
		for(int i = 0; i < (int)poss.size(); i++){
			cout << 1;
			for(int j = 1; j < N; j++){
				cout << ' ' << poss[i][j]-'0';
			}
			cout << '\n';
		}
	}
}
