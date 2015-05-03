#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

class SegmentTree {
private:
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1)+1; }
	
	void build(int p, int L, int R){
		if(L == R) st[p] = A[L];
		else{
			build( left(p), L				 , ( L + R ) / 2);
			build(right(p), ( L + R ) / 2 + 1, R			);
			int s1 = st[left(p)], s2 = st[right(p)];
			st[p] = (s1 + s2);
		}
	}
	
	int rsq(int p, int L, int R, int i, int j){
		if( i > R || j < L ) return -1;
		if (L >= i && R <= j) return st[p];
		
		int s1 = rsq(left(p) , L			, (L+R) / 2, i, j);
		int s2 = rsq(right(p), (L+R) / 2 + 1, R		   , i, j);
		if(s1 == -1) return s2;
		if(s2 == -1) return s1;
		return (s1 + s2);
	}
	
	void update(int p, int i, int j, int L, int R, char val){
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
			if(L == R) {
				A[L] = st[p];
				return ;
			}
		}
		update(left(p), i, j, L, (L+R)/2, val);
		update(right(p), i, j, (L+R)/2+1, R, val);
		st[p] = st[left(p)]+st[right(p)];
	}
public:
	SegmentTree(const vi &_A){
		A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n-1);
	}
	int rsq(int i, int j){ return rsq(1, 0, n-1, i, j); }
	
	void update(int i, int j, char val){ update(1, i, j, 0, n-1, val); }
};
vector <int> pirates;
int main(){
	ios_base::sync_with_stdio(false);
	
	int t, m, n, s, q, a, b;
	char c;
	string bits, pir;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		pirates.clear();
		s = 0;
		pir = "";
		cin >> m;
		while(m--){
				cin >> n;
				cin >> bits;
				s+= n*bits.size();
				while(n-- > 0)
					pir = pir+bits;
				
		}
		for(int i = 0; i < (int)pir.size();i++){
			pirates.push_back(pir[i]-'0');
		}
		SegmentTree st(pirates);
		
		cin >> q;
		int ind = 1;
		cout << "Case " << caso<< ":\n";
		while(q--){
			cin >> c >> a >> b;
			if(c == 'S'){
				cout << "Q" << ind++ << ": " << st.rsq(a,b) << '\n';
			}
			else{
				st.update(a,b,c);
			}
		}
	}
}
