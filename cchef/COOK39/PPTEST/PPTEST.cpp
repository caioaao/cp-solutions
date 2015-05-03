#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int,map<int,int> > memo;

vector<int>C,P,T;
int n;

int runIt(int id, int remW){
	if(memo[id].count(remW)) return memo[id][remW];
	if(id == n || remW == 0) return 0;
	if( T[id] <= remW)
		return memo[id][remW] = max(runIt(id+1, remW),runIt(id+1, remW-T[id])+C[id]*P[id]);
	
	return memo[id][remW] = runIt(id+1, remW);
}

int main(){
	ios_base::sync_with_stdio(false);
	int Ts, W;
	cin >> Ts;
	while(Ts--){
		cin >> n >> W;
		memo.clear();
		C.assign(n,0);
		P.assign(n,0);
		T.assign(n,0);
		for(int i = 0; i < n; i++){
			cin >> C[i] >> P[i] >> T[i];
		}
		cout << runIt(0,W) << '\n';
	}
}
