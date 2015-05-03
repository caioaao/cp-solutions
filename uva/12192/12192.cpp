#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<long long> > diags;
int main(){
	ios_base::sync_with_stdio(false);
	long long answ;
	int n, m, x, q, a, b;
	cin >> n >> m;
	vector<long long>::iterator first, last;
	
	while(n!=0 || m!=0){
		diags.assign(2*max(m,n),vector<long long>());
		
		for(long long j = 0; j < n; j++){
			for(long long i = 0; i < m; i++){
				cin >> x;
				diags[j-i + max(m,n)].push_back(x);
			}
		}
		
		cin >> q;
		
		while(q--){
			cin >> a >> b;
			answ=0;
			for(vector<vector<long long> >::iterator i = diags.begin(); i != diags.end(); ++i){
				first = lower_bound(i->begin(),i->end(), a);
				
				if(first != i->end() && *first >= a){
					last = upper_bound(first, i->end(), b);
					if(*(last-1) <=b)
						answ = max(answ, (long long)(last-first));
				}
			}
			cout << answ << '\n';
		}
		cout << "-\n";
		cin >> n >> m;
	}
}
