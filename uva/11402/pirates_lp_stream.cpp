#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct node{
	int s;
	char lazy;
}

int st[4096000];
char lazy[4096000];
	
class SegmentTree {
public:
	string sA;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1)+1; }
	
	void build(int p, int L, int R){
		if(L == R) st[p] = sA[L]-'0';
		else{
			build( left(p), L				 , ( L + R ) / 2);
			build(right(p), ( L + R ) / 2 + 1, R			);
			int s1 = st[left(p)], s2 = st[right(p)];
			st[p] = (s1 + s2);
		}
	}
	
	int rsq(int p, int L, int R, int i, int j){
		if( i > R || j < L ) return -1;
		if(lazy[p] != 'n'){
			switch(lazy[p]){
				case 'F':
					st[p] = (R-L+1);
				break;
				case 'E':
					st[p] = 0;
				break;
				case 'I':
					st[p] = (R-L+1)-st[p];
			}
			if(L != R){
				if(lazy[p] == 'I'){
					if(lazy[left(p)] == 'F') lazy[left(p)] = 'E';
					else if(lazy[left(p)] == 'E') lazy[left(p)] = 'F';
					else if(lazy[left(p)] == 'I') lazy[left(p)] = 'n';
					else lazy[left(p)] = 'I';
					
					if(lazy[right(p)] == 'F') lazy[right(p)] = 'E';
					else if(lazy[right(p)] == 'E') lazy[right(p)] = 'F';
					else if(lazy[right(p)] == 'I') lazy[right(p)] = 'n';
					else lazy[right(p)] = 'I';
				}
				else{
					lazy[left(p)] = lazy[p];
					lazy[right(p)] = lazy[p];
				}
			}
			lazy[p] = 'n'; 
		}
		if (L >= i && R <= j) return st[p];
		
		int s1 = rsq(left(p) , L			, (L+R) / 2, i, j);
		int s2 = rsq(right(p), (L+R) / 2 + 1, R		   , i, j);
		if(s1 == -1) return s2;
		if(s2 == -1) return s1;
		return (s1 + s2);
	}
	
	void update(int p, int i, int j, int L, int R, char val){
		if(lazy[p] != 'n'){
			switch(lazy[p]){
				case 'F':
					st[p] = (R-L+1);
				break;
				case 'E':
					st[p] = 0;
				break;
				case 'I':
					st[p] = (R-L+1)-st[p];
			}
			if(L != R){
				if(lazy[p] == 'I'){
					if(lazy[left(p)] == 'F') lazy[left(p)] = 'E';
					else if(lazy[left(p)] == 'E') lazy[left(p)] = 'F';
					else if(lazy[left(p)] == 'I') lazy[left(p)] = 'n';
					else lazy[left(p)] = 'I';
					
					if(lazy[right(p)] == 'F') lazy[right(p)] = 'E';
					else if(lazy[right(p)] == 'E') lazy[right(p)] = 'F';
					else if(lazy[right(p)] == 'I') lazy[right(p)] = 'n';
					else lazy[right(p)] = 'I';
				}
				else{
					lazy[left(p)] = lazy[p];
					lazy[right(p)] = lazy[p];
				}
			}
			lazy[p] = 'n'; 
		}
		if(i > R || j < L) return ;	
		if(L >= i && R <= j){
			switch(val){
				case 'F':
					st[p] = (R-L+1);
				break;
				case 'E':
					st[p] = 0;
				break;
				case 'I':
					st[p] = (R-L+1)-st[p];
			}
			if(L != R){
				if(val == 'I'){
					if(lazy[left(p)] == 'F') lazy[left(p)] = 'E';
					else if(lazy[left(p)] == 'E') lazy[left(p)] = 'F';
					else if(lazy[left(p)] == 'I') lazy[left(p)] = 'n';
					else lazy[left(p)] = 'I';
					
					if(lazy[right(p)] == 'F') lazy[right(p)] = 'E';
					else if(lazy[right(p)] == 'E') lazy[right(p)] = 'F';
					else if(lazy[right(p)] == 'I') lazy[right(p)] = 'n';
					else lazy[right(p)] = 'I';
				}
				else{
					lazy[left(p)] = val;
					lazy[right(p)] = val;
				}
			}
			return ;
		}
		update(left(p), i, j, L, (L+R)/2, val);
		update(right(p), i, j, (L+R)/2+1, R, val);
		st[p] = st[left(p)]+st[right(p)];
	}
	SegmentTree(const string &_A){
		sA = _A; n = (int)sA.size();
		memset(st,0, 4*n*sizeof(int));
		memset(lazy, 'n', sizeof(char)*4*n);
		build(1, 0, n-1);
	}
	int rsq(int i, int j){ return rsq(1, 0, n-1, i, j); }
	
	void update(int i, int j, char val){ update(1, i, j, 0, n-1, val); }
};
int main(){
	ios_base::sync_with_stdio(false);
	
	int t, m, n, q, a, b;
	char c;
	string bits, pir;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		pir = "";
		cin >> m;
		while(m-- > 0){
				cin >> n;
				cin >> bits;
				while(n--)
					pir = pir+bits;
				
		}
		SegmentTree st(pir);
		
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
