#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <functional>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <stack>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int played[1010][1010];
vector<ii> games;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll n,k, kL;
	while(cin >> n >> k){
		
		memset(played,0,sizeof played);
		games.assign(n*k,ii());
		
		bool ok = true;
		
		for(int i = 0; i < n; i++){
			kL = k;
			for(int j = 0; j < n; j++){
				if(kL == 0) break;
				if(i != j && !played[i][j]){
					played[i][j] = played[j][i] = 1;
					games[i*k +(k-kL)] = ii(i+1,j+1);
					kL--;
				}
			}
			if(kL > 0){
				//~ cout << i << &#39; &#39; << kL << endl;
				ok = false;
				break;
			}
		}
		if(!ok){
			cout << "-1\n";
			//~ for(int i = 0; i < n; i++){
				//~ for(int j = 0; j < n; j++)
					//~ cout << played[i][j];
				//~ cout << endl;
			//~ }
			
		}
		else{
			cout << n*k << &#39;\n&#39;;
			for(int i = 0; i < n*k; i++)
				cout << games[i].first << &#39; &#39; << games[i].second << &#39;\n&#39;;
		}
	}
}
