#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void st_build(vi &t, vi &A, int vertex, int L, int R){
	if(L==R){
		t[vertex] = L;
		return ;
	}
	int nL = 2*vertex, nR = nL+1;
	st_build(t,A,nL,L,(L+R)/2);
	st_build(t,A,nR,(L+R)/2+1,R);
	int lContent = t[nL], rContent = t[nR];
	int lValue = A[lContent], rValue = A[rContent];
	t[vertex] = ( lValue >= rValue ) ? lContent : rContent;
}

void st_create(vi &t, vi &A){
	int len = (int)(2*pow(2.0,floor((log((double)A.size()) / log(2.0))+1)));
	t.assign(len,-1);
	st_build(t,A,1,0, A.size()-1);
}

int st_rmq(vi &t, vi &A, int vertex, int L, int R, int i, int j){
	if(i > R || j < L) return -1;
	if(L >= i && R <= j) return t[vertex];

	int p1 = st_rmq(t,A,2*vertex,L, (L+R)/2,i,j);
	int p2 = st_rmq(t,A,2*vertex+1,  (L+R)/2 + 1, R,i,j);
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	if(A[p1] > A[p2]) return p1;
	return p2;
}

int st_rmq(vi &t, vi &A, int i, int j){
	return st_rmq(t, A, 1, 0, A.size()-1, i, j);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, q, dummy, last, begin, end, amt, ans, i2b, i2e;
	vi t, A, num, b; // Arvore, tamanho seq, seq e comeco da seq
	cin >> n;
	while(n != 0){
		cin >> q;
		A.assign(n,0); num.assign(n,0); b.assign(n,0);
		cin >> num[0];
		last = num[0]; b[0] = 0;amt = 1;
		for(int k = 1; k < n; k++){
			cin >> num[k];
			if(num[k] != last){
				last = num[k];
				for(int i = b[k-1]; i < k; i++){
					A[i] = amt;
				}
				b[k] = k;
				amt = 1;
			}else {
				b[k] = b[k-1];
				amt++;
			}
		}
		for(int i = b[n-1]; i < n; i++){
			A[i] = amt;
		}

		st_create(t,A);

		while(q--){
			cin >> begin >> end;
			begin -= 1; end -= 1;
			if(num[begin] == num[end]){
				cout << end-begin+1 << "\n";
				continue;
			}
			ans = max(b[begin]+A[begin]-begin,end-b[end]+1);
			i2b = b[begin]+A[begin]; i2e = b[end]-1;
			//cout << i2b << ' ' << i2e << ":  ";
			//cout << b[begin]+A[begin]-begin << ' ' << end-b[end]+1 << ",  ";
			if(i2b <= i2e) ans = max(ans, A[st_rmq(t,A,i2b,i2e)]);
			cout << ans << '\n';
			//
			//i2b = begin+A[begin]-1; i2e = b[end];
			//cout << max(st_rmq(t,A,,),) << '\n';
			
		}
		cin >> n;
	}
}
