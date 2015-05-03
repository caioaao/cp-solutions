#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <functional>

#define MAX_N 105

using namespace std;
typedef vector<int> vi;

map<string,int> dict;
map<int, string> bdict;
int N, M, indeg[MAX_N];
vector<vi> AdjMat;
int main(){
	ios_base::sync_with_stdio(false);
	string name,name1,name2;
	int caso = 1;
	while(cin>>N){
		memset(indeg, 0, sizeof indeg);
		dict.clear();
		for(int i = 0; i < N; i++){
			cin >> name;
			dict[name] = i;
			bdict[i] = name;
		}
		AdjMat.assign(N, vi(N,0));
		cin >> M;
		for(int i = 0; i < M; i++){
			cin >> name1 >> name2;
			if(AdjMat[dict[name1]][dict[name2]] != 1){
				AdjMat[dict[name1]][dict[name2]] = 1;
				indeg[dict[name2]]++;
			}
		}
		
		priority_queue<int, vi, greater<int> > q;
		cout << "Case #" << caso++ << ": Dilbert should drink beverages in this order:";
		for(int i = 0; i < N; i++)
			if(indeg[i] == 0) q.push(i);
			
		while(!q.empty()){
			int p = q.top(); q.pop();
			cout << ' ' << bdict[p];
			for(int i = 0; i < N; i++){
				if(AdjMat[p][i])
					if(--indeg[i] == 0) q.push(i);
			}
		}
		cout << ".\n\n";
	}
}
