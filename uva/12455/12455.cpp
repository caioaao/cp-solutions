#include <iostream>
#include <map>
#include <algorithm>

#define MAX_N 1001
#define MAX_P 21


using namespace std;

int T, n, p,bars[MAX_P], somas[MAX_P];
map <int,map<int, bool> > memo;
bool conta(int id, int s){
	if(memo[id].count(s)) return memo[id][s];
	if(s == 0) return true;
	if(id == p || s < 0 || somas[id] < s) return false;
	return (memo[id][s] = (conta(id+1,s-bars[id]) || conta(id+1,s)));
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	while(T--){
		memo.clear();
		cin >> n >> p;
		for(int i = 0; i < p; i++){
			cin >> bars[i];
		}
		sort(bars, bars+p);
		for(int i = p-1; i >= 0; i--){
			somas[i] = bars[i]+(i<p-1? somas[i+1] : 0);
		}
		if(conta(0, n))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
