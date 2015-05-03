#include <iostream>
using namespace std;

int l[100001];
int r[100001];

int main(){
	ios_base::sync_with_stdio(false);
	int b, s, il, ir;
	cin >> s >> b;
	while(b != 0 || s != 0){
		for(int i = 1; i <= s; i++){
				l[i] = i-1; r[i] = i+1;
		}
		
		while(b--){
			cin >>il >> ir;
			l[r[ir]] = l[il];
			r[l[il]] = r[ir];
			//r[il] = r[ir];
			//l[ir] = l[il];
			if(l[il] == 0 || l[il] > s) cout << "*";
			else cout << l[il];
			
			cout << ' ';
			if(r[ir] == 0 || r[ir] > s) cout << "*";
			else cout << r[ir];
			cout << '\n';
		}
		cout << "-\n";
		
		cin >> s >> b;
	}
}
