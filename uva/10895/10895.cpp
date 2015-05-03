#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<int>::iterator vii;

int  main(){
	int m, n, rs, cn, r;
	vi rsizes;
	vector<vi> rows,nums;
	cin >> m >> n;
	while(!cin.eof()){
		rsizes.assign(n,0);
		rows.assign(n, vi());
		nums.assign(n, vi());
		vi cols;
		for(int i = 0; i < m; i++){
			cols.clear();
			cin >> rs;
			for(int j = 0; j < rs; j++){
				cin >> cn;
				rsizes[cn-1]++;
				cols.push_back(cn);
				nums[cn-1].push_back(i+1);
			}
			for(int j = 0; j < rs; j++){
				cin >> r;
				rows[cols[j]-1].push_back(r);
			}
		}


		cout << n << ' ' << m << endl;
		for(int i = 0; i < n; i++){
			cout << rsizes[i];

			for(vii j = nums[i].begin(); j != nums[i].end(); j++){
				cout << ' ' << (*j);
			}
			cout << endl;
			if(rsizes[i]>0){ cout << rows[i][0]; 
			for(vii j = rows[i].begin()+1; j != rows[i].end(); j++){
				cout << ' ' << (*j);
			}}
			cout << endl;
		}

		cin >> m >> n;
	}
}
