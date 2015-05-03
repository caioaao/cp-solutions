#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

vi ts, bests, memo, seq;
vector<bool> pode;

int best(int n){
	if(n <= 0) return 0;
	if(memo[n] > 0) return memo[n];
	ll ne;
	//cout << "ooi" << n;
		
	for(vi::iterator i = ts.begin(); i != ts.end(); ++i){
		if(!pode[*i])continue;
		if(*i == n){
			bests[n] = n;
			memo[n] = n;
			break;
		}
		if(*i < n){
			pode[*i] = 0;
			ne = best(n-*i)+*i;
			pode[*i] = 1;
			if(ne > memo[n]){
				memo[n] = ne;
				bests[n] = *i;
			}
			if(memo[n] == n) break;
		}
	}
	return memo[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	ll n, trs, t;
	while(cin >> n){
		cin >> trs;
		ts.clear(); memo.assign(n+1, 0);bests.assign(n+1,-1); pode.assign(n+1,1); seq.clear();
		for(int i = 0; i < trs; i++){
			cin >> t;
			ts.push_back(t);
		}
		ll s = best(n), nxt = bests[n], st = n;
		while(nxt > 0){
			cout << nxt << ' ';
			st -= nxt;
			nxt = bests[st];
		}
		cout << "sum:" << s << '\n';
	}
}
