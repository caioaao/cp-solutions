#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>

int primes[100000];
int kprimes[100000];
int min_combs[6];

int kprime(int num){
	if(kprimes[num] == -1){
		int pf_idx = 0, pf = primes[pf_idx], k = 0;
		while(num != 1 && (pf * pf < num) && k <= 5){
			if(num % pf == 0) {
				k++;
				while(num % pf == 0) num /= pf;
			}
			pf = primes[++pf_idx];
		}
		if(num != 1){
			k++;
		}
		kprimes[num] = k;
		return(k);
	}
	else{
		return kprimes[num];
	}
}

int main(){
	memset(kprimes,-1,sizeof(kprimes));
	
	 //Create the various different variables required
	 int limit = 100000;
	 int root = ceil(sqrt(limit));
	 bool sieve[limit];
	 int insert = 2;
	 primes[0] = 2;
	 primes[1] = 3;
	 for (int z = 0; z < limit; z++) sieve[z] = false; //Not all compilers have false as the default boolean value
	 for (int x = 1; x <= root; x++)
	 {
	 for (int y = 1; y <= root; y++)
	 {
	 //Main part of Sieve of Atkin
	 int n = (4*x*x)+(y*y);
	 if (n <= limit && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;
	 n = (3*x*x)+(y*y);
	 if (n <= limit && n % 12 == 7) sieve[n] ^= true;
	 n = (3*x*x)-(y*y);
	 if (x > y && n <= limit && n % 12 == 11) sieve[n] ^= true;
	 }
	 }
	 //Mark all multiples of squares as non-prime
	 for (int r = 5; r <= root; r++) if (sieve[r]) for (int i = r*r; i < limit; i += r*r) sieve[i] = false;
	 //Add into prime array
	 for (int a = 5; a < limit; a++)
	 {
	 if (sieve[a])
	 {
	 primes[insert] = a;
	 insert++;
	 kprimes[a] = 1;
	 }
	 }
	kprimes[0] = 0;
	kprimes[1] = 0;
	kprimes[2] = 1;
	kprimes[3] = 1;

	min_combs[0] = 1;
	min_combs[1] = 2;
	min_combs[2] = 6;
	min_combs[3] = 30;
	min_combs[4] = 210;
	min_combs[5] = 2310;

	int k, a, b, t, start, ks;
	scanf("%d\n", &t);

	// clock_t t1 = clock();

	for(int count = 0; count < t; count++){
		scanf("%d %d %d\n", &a, &b, &k);

		start = std::max(a, min_combs[k]);
		// printf("Start: %d End %d\n", start, b);
		ks = 0;
		for(int s = start; s <= b; s++){
			if(kprime(s) == k){
				ks++;
			}
		}
		
		printf("%d\n",ks);
	}
	// float diff = (((float)clock() - (float)t1) / 1000000.0F ) * 1000;   
	// printf("Tempo: %f\n\n",diff);  
}