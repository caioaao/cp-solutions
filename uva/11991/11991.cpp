#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
	int n,m, v, k;
	cin >> n >> m;

	while(!cin.eof()){
		map<int,vi >adj;
	
		for(int i = 0; i < n; i++){
			cin >> v;
			adj[v].push_back(i+1);
		}
		for(int i = 0; i < m; i++){
			cin >> k >> v;

			if(adj[v].size() >= k) cout << adj[v][k-1];
			else cout << 0;
			cout << endl;
		}
		cin >> n >> m;
	}
}
