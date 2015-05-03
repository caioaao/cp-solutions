#include <cstdio>

int main(){
	int t,n,m,k, s, spaces;
	scanf("%d\n",&t);
	while(t--){
		scanf("%d %d %d\n", &m, &n, &k);
		spaces = (m*n)-2;
		if(spaces <= 0) s = 0;
		else if(m == 1 || n == 1) s = k;
		else{
			s = k/2;
			if(k%2 != 0) s++;
		}


		printf("%d\n", s);
	}
}