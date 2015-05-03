#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 210
#define MAX_M 11
#define MAX_D 45

typedef long long ll;

ll memo[MAX_N][MAX_M][MAX_D], d, m, n, q, nums[MAX_N];

ll knap(int id, int mLeft, ll soma){
	int resto = soma%d+d;/*;
	if(soma > 0) resto = soma%d+d;
	else resto = d - soma%d;*/
	if(memo[id][mLeft][resto] != -1) return memo[id][mLeft][resto];
	if(mLeft == 0){
		if(soma%d == 0) return memo[id][mLeft][resto] = 1;
		else return 0;
	}
	if(id == n) return memo[id][mLeft][resto] = 0;
	return memo[id][mLeft][resto] = (knap(id+1, mLeft, soma) + knap(id+1,mLeft-1, soma+nums[id]));
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n >> q;
	
	int set = 1;
	
	while(n!=0 || q!=0){
		cout << "SET " << set++ <<  ":\n";
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		for(int i = 1; i <= q; i++){
			memset(memo, -1, sizeof memo);
			cin >> d >> m; 
			cout 	<< "QUERY " << i << ": " << knap(0,m,0) << '\n';
		}
		
		cin >> n >> q;
	}
}
