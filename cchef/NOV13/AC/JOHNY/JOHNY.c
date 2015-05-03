#include <stdio.h>

int main(){
	int T, N, k;
	int songs[101];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int i;
		for(i = 0; i < N; i++){
			scanf("%d",&songs[i]);
		}
		scanf("%d",&k);
		k = songs[k-1];
		int pos = 1;
		for(i = 0; i < N; i++) if(songs[i] < k) pos++;
		printf("%d\n",pos);
	}
	return 0;
}
