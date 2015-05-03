	#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <algorithm>

#define MAX_N 100000

using namespace std;

typedef long long ll;

ll a[MAX_N], b[MAX_N];
ll poss[MAX_N];
	
bool sortfunc(ll a, ll b){
	if(a >2 && b >2) return a > b;
	else return(b*log(a)<a*log(b));
	
	return true;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	ll t, n;
	ll possSum;
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a,a+n, sortfunc);
		for(ll i = 0; i < n; i++){
			cin >> b[i];
		}
		ll lastEl = 0;
		poss[0] = 0;
		for(ll i = 0, j = 0; i < n && j < n && j >= 0; j++){
			if(sortfunc(b[j],a[i])) poss[i]++;
			else if(++i < n){
				poss[i] = poss[i-1];
				j--;
				lastEl = i;
			}
		}
		possSum = 0;
		for(ll i = 0; i <= lastEl; i++){
			possSum += poss[i];
		}
	//	cout << possSum << endl;
		cout << fixed << setprecision(6) << possSum/(double)n << '\n';
	}
}
