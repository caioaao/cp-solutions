#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define vinteri vector<interval>::iterator
#define vpi vector<int>::iterator
#define vpii vector<vector<int> >::iterator

struct interval{
	int a,b;
};

vector<interval> intervals;
vector<vector<int> > edges;

bool bfs(int a, int b){
	if(edges.size() == 0) return false;
	int *states = new int[intervals.size()]; // 0 new, 1 discovered, 2 processed
	// memset(states, 0, sizeof(states));
	for(int i = 0; i < intervals.size(); i++){
		states[i] = 0;
	}
	queue<int> q;
	int now, test;
	q.push(a);
	while(!q.empty()){
		now = q.front();
		q.pop();
		// cout << now << endl;

		if(now == b)
			return true;

		states[now] = 2;

		for(vpi ii = edges[now].begin(); ii != edges[now].end(); ++ii){
			test = *ii;
			// cout << "Estado de " << test-1 << ": " << states[test-1] << endl;

			if(test-1 == b)
				return true;
			if(states[test-1] == 0){
				states[test-1] = 1;
				q.push(test-1);
			}
		}
	}
	return false;
}

int main(){
	int t, type, a, b, i=0;
	cin >> t;
	while(t--){
		cin >> type >> a >> b;
		if(type == 1){
			i++;
			edges.resize(edges.size()+1);
			for(int ii = 0; ii < intervals.size(); ii++){
				if((a < intervals[ii].b && a > intervals[ii].a) || (b < intervals[ii].b && b > intervals[ii].a)){
					// edges[ii].push_back(i);
					edges[i-1].push_back(ii+1);
				}
				if((a < intervals[ii].a && b > intervals[ii].a) || (b > intervals[ii].b && a < intervals[ii].b)){
					edges[ii].push_back(i);
					// edges[i-1].push_back(ii+1);
				}
			}

			interval dummy;
			dummy.a = a;
			dummy.b = b;

			// Add interval
			intervals.push_back(dummy);
		}
		else{
			// int n = 0;
			// for(vpii i = edges.begin(); i != edges.end(); ++i){
			// 	n++;
			// 	cout << "Edges de " << n << ": ";
			// 	for(vpi ii = (*i).begin(); ii != (*i).end(); ++ii) cout << (*ii) << " ";
			// 		cout << endl;
			// }
			cout << (bfs(a-1,b-1) ? "YES\n" : "NO\n");
		}
	}
}