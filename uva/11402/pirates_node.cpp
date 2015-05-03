#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct node{
	int s;
	char lazy;
} st[4096000];

int pir[1024001], psize, j;
class SegmentTree {
public:
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1)+1; }
	
	void build(int p, int L, int R){
		if(L == R) st[p].s = pir[L];
		else{
			build( left(p), L				 , ( L + R ) / 2);
			build(right(p), ( L + R ) / 2 + 1, R			);
			st[p].s = st[left(p)].s+st[right(p)].s;
		}
	}
	
	int rsq(int p, int L, int R, int i, int j){
		if( i > R || j < L ) return 0;
		if(st[p].lazy != 'n'){
			switch(st[p].lazy){
				case 'F':
					st[p].s = (R-L+1);
				break;
				case 'E':
					st[p].s = 0;
				break;
				case 'I':
					st[p].s = (R-L+1)-st[p].s;
			}
			if(L != R){
				if(st[p].lazy == 'I'){
					if(st[left(p)].lazy == 'F') st[left(p)].lazy = 'E';
					else if(st[left(p)].lazy == 'E') st[left(p)].lazy = 'F';
					else if(st[left(p)].lazy == 'I') st[left(p)].lazy = 'n';
					else st[left(p)].lazy = 'I';
					
					if(st[right(p)].lazy == 'F') st[right(p)].lazy = 'E';
					else if(st[right(p)].lazy == 'E') st[right(p)].lazy = 'F';
					else if(st[right(p)].lazy == 'I') st[right(p)].lazy = 'n';
					else st[right(p)].lazy = 'I';
				}
				else{
					st[left(p)].lazy = st[p].lazy;
					st[right(p)].lazy = st[p].lazy;
				}
			}
			st[p].lazy = 'n'; 
		}
		if (L >= i && R <= j) return st[p].s;
		
		int s1 = rsq(left(p) , L			, (L+R) / 2, i, j);
		int s2 = rsq(right(p), (L+R) / 2 + 1, R		   , i, j);
		
		return (s1 + s2);
	}
	
	void update(int p, int i, int j, int L, int R, char val){
		if(st[p].lazy != 'n'){
			switch(st[p].lazy){
				case 'F':
					st[p].s = (R-L+1);
				break;
				case 'E':
					st[p].s = 0;
				break;
				case 'I':
					st[p].s = (R-L+1)-st[p].s;
			}
			if(L != R){
				if(st[p].lazy == 'I'){
					if(st[left(p)].lazy == 'F') st[left(p)].lazy = 'E';
					else if(st[left(p)].lazy == 'E') st[left(p)].lazy = 'F';
					else if(st[left(p)].lazy == 'I') st[left(p)].lazy = 'n';
					else st[left(p)].lazy = 'I';
					
					if(st[right(p)].lazy == 'F') st[right(p)].lazy = 'E';
					else if(st[right(p)].lazy == 'E') st[right(p)].lazy = 'F';
					else if(st[right(p)].lazy == 'I') st[right(p)].lazy = 'n';
					else st[right(p)].lazy = 'I';
				}
				else{
					st[left(p)].lazy = st[p].lazy;
					st[right(p)].lazy = st[p].lazy;
				}
			}
			st[p].lazy = 'n'; 
		}
		if(i > R || j < L) return ;	
		if(L >= i && R <= j){
			switch(val){
				case 'F':
					st[p].s = (R-L+1);
				break;
				case 'E':
					st[p].s = 0;
				break;
				case 'I':
					st[p].s = (R-L+1)-st[p].s;
			}
			if(L != R){
				if(val == 'I'){
					if(st[left(p)].lazy == 'F') st[left(p)].lazy = 'E';
					else if(st[left(p)].lazy == 'E') st[left(p)].lazy = 'F';
					else if(st[left(p)].lazy == 'I') st[left(p)].lazy = 'n';
					else st[left(p)].lazy = 'I';
					
					if(st[right(p)].lazy == 'F') st[right(p)].lazy = 'E';
					else if(st[right(p)].lazy == 'E') st[right(p)].lazy = 'F';
					else if(st[right(p)].lazy == 'I') st[right(p)].lazy = 'n';
					else st[right(p)].lazy = 'I';
				}
				else{
					st[left(p)].lazy = val;
					st[right(p)].lazy = val;
				}
			}
			return ;
		}
		update(left(p), i, j, L, (L+R)/2, val);
		update(right(p), i, j, (L+R)/2+1, R, val);
		st[p].s = st[left(p)].s+st[right(p)].s;
	}
	SegmentTree(int _n){
		n = _n;
		memset(st,0, 4*n*sizeof(node));
		build(1, 0, n-1);
	}
	int rsq(int i, int j){ return rsq(1, 0, n-1, i, j); }
	
	void update(int i, int j, char val){ update(1, i, j, 0, n-1, val); }
};
int main(){
	ios_base::sync_with_stdio(false);
	
	int t, m, n, q, a, b, sum;
	char c;
	string bits;
	
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		memset(pir,0, sizeof(pir));
		j = 0; sum = 0;
		cin >> m;
		while(m-- > 0){
				cin >> n;
				cin >> bits;
				psize = (int)bits.size();
				sum+= psize*n;
				while(n-- > 0)
					for(int i = 0; i < psize; i++,j++)
					pir[j] = bits[i]-'0';
				
		}
		SegmentTree st(sum);
		
		cin >> q;
		int ind = 1;
		cout << "Case " << caso<< ":\n";
		while(q-- > 0){
			cin >> c >> a >> b;
			if(c == 'S'){
				cout << "Q" << ind++ << ": " << st.rsq(1, 0, st.n-1,a,b) << '\n';
			}
			else{
				st.update(1,a,b, 0, st.n-1, c);
			}
		}
	}
}
