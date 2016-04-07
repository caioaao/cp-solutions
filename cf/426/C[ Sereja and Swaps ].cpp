#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> vals;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	while(cin >> n >> k){
		vals.assign(n,0);
		for(int i = 0; i < n; i++){
			cin >> vals[i];
		}
		
		vector<int> valsIn, valsOut;
		int best = -2000000;
		for(int i = 0; i < n; i++){
			for(int l = 1; l <= n - i; l++){
				valsIn = vector<int>(vals.begin()+i, vals.begin()+i+l);
				if((int)valsIn.size() < n){
					valsOut = vals;
					sort(valsIn.begin(), valsIn.end());
					
					for(int s = i; s < i+l; s++) valsOut[s] = -2000000;
					sort(valsOut.begin(), valsOut.end());
					
					int kL = k, ind1 = 0, ind2 = 0;
					int maiores = 0;
					while(ind1 < l && ind2 < n && kL > 0){
						if(valsIn[ind1] < valsOut[ind2]){
							maiores++;
							ind1++; ind2++;
							kL--;
						}
						else ind2++;
					}
					
					for(int ind = n - 1, ind2 = 0; ind >= n - maiores; ind--, ind2++)
						swap(valsIn[ind2], valsOut[ind]);
				}
				
				int  soma = 0;
				for(int ind = 0; ind < l; ind++) soma+= valsIn[ind];
				
				best = max(soma, best);
			}
		}
		
		cout << best << &#39;\n&#39;;
	}
}
