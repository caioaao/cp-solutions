#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>

#define INF 1e9

using namespace std;

typedef vector<int> vi;
typedef map<int, vi> mvi;
vector<string> dict;
map<string, int> dictT;

map<int, vi> AdjList;
vi dist;

int main(){
	int T;
	stringstream ss;
	string s, s1, s2;
	cin >> T;
	bool first = true;
	while(T--){
		if(!first)cout << '\n';
		first = false;
		dict.clear(); dictT.clear(); dist.clear();AdjList.clear();
		cin >> s;
		int i = 0;
		while(s != "*"){
			dict.push_back(s);
			dictT[s] = i;
			for(int j = i-1; j >=0; j--){
				if(dict[j].size() == s.size()){
					int diff = 0;
					for(int k = 0; k < (int)s.size(); k++) diff+= !(dict[j][k] == s[k]);
					if(diff == 1){
						AdjList[i].push_back(j);
						AdjList[j].push_back(i);
					}
				}
			}
			cin >> s;
			i++;
		}
		
		getline(cin, s);
		getline(cin,s);
		while(s != ""){
			ss.clear();
			ss.str(s);
			ss >> s1 >> s2;
			cout << s1 << ' ' << s2 << ' ';
			dist.assign(i, INF);
			dist[dictT[s1]] = 0;
			queue<int> q; q.push(dictT[s1]);
			
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int j = 0; j < (int)AdjList[u].size(); j++){
					int v = AdjList[u][j];
					if(dist[v] == INF){
						dist[v] = dist[u]+1;
						q.push(v);
					}
				}
			}
			cout << dist[dictT[s2]] << '\n';
			
			getline(cin,s);
		}
	}
}
