#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll N;
vll A, st;

int left(int p){ return p << 1;}
int right(int p){ return (p << 1) + 1;}

void build(int p, int L, int R){
	if(L==R)
		st[p] = A[R];
	else{
		build(left(p), L, (L+R)/2);
		build(right(p), (L+R)/2 + 1, R);
		st[p] = st[left(p)]+st[right(p)];
	}
}

void build(){
	st.assign(4*N, 0);
	build(1, 0, N-1);
}

void update(int p, int L, int R, int x, int val){
	if(x > R || x < L) return ;
	if(L <= x && R >= x){
		st[p] += val;
		if(L != R){
			update(left(p), L, (R+L)/2, x, val);
			update(right(p), (R+L)/2+1, R, x, val);
		}
	}
}

void update(int x, int val){
	update(1, 0, N-1, x, val);
}

ll query(int p, int L, int R, int a, int b){
	if(a > R || b < L) return 0;
	if(L >= a && R <= b) return st[p];
	
	return query(left(p), L, (L+R)/2, a, b)+query(right(p), (L+R)/2 +1, R, a, b);
}

ll query(int a, int b){
	return query(1, 0, N-1, a, b);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	ll Q, a, b;
	char action;
	while(cin >> N >> Q){
		A.assign(N,0);
		for(int i = 0; i < N; i++){
			cin >> A[i]; A[i]-=1000;
		}
		
		build();

		for(int i = 0; i < Q; i++){
			cin >> action >> a >> b;
			if(action == 'S')
				cout << query(a,b)+(b-a+1)*1000 << '\n';
			else
				update(a,(action == 'G' ? 1 : -1)*b);
		}
	}
}
