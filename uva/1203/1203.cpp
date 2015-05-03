#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

typedef pair<int, int> pi;
typedef priority_queue<pi> pqpi;

pqpi queries;
map<int,int> spans;


int main(){
	int id, span;
	string s;
	cin >> s;
	while(s != "#"){
		cin >> id >> span;
		queries.push(make_pair(-span,-id));
		spans[id] = -span;
		cin >> s;
	}
	int k;
	pi now;
	cin >> k;
	while(k--){
		now = queries.top();
		queries.pop();
		cout << -now.second << '\n';
		queries.push(make_pair(now.first+spans[-now.second],now.second));
	}
}
