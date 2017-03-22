#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 210
#define MAX_M 20
#define MAX_D 45

typedef long long ll;

ll memo[MAX_N][MAX_M][MAX_D], d, m, n, q, nums[MAX_N];

ll knap(){
    for(int i = 0; i <= m; ++i)
        for(int j = 0; j < d; ++j) memo[n][i][j] = 0;
    memo[n][m][0] = 1;

    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j <= m; ++j) {
            for(int k = 0; k < d; ++k) {
                memo[i][j][k] = memo[i + 1][j][k];
                if(j < m) {
                    memo[i][j][k] += memo[i + 1][j + 1][(((k + nums[i]) % d) + d) % d];
                }
            }
        }
    }

    return memo[0][0][0];
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
			cin >> d >> m;
			cout 	<< "QUERY " << i << ": " << knap() << '\n';
		}

		cin >> n >> q;
	}
}
