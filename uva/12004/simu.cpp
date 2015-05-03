#include <iostream>
#include <algorithm>

using namespace std;

int findSwaps( int n, int *a )
{
    int count = 0, i, j, temp, b[100000];

    for( i = 0; i < n; i++ ) {
        b[i] = a[i];
    }
    for( i = 0; i < n; i++ ) {
        for( j = 0; j < n - 1; j++ ) {
            if( b[j] > b[j+1] ) {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;

                count++;
            }
        }
    }
    return count;
}

int main(){
	for(int n = 1; n < 10; n++){
		int a[10] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		long long ans = 0, counter = 1;
		while(next_permutation(a, a+n)){
			ans+=findSwaps(n,a);
			counter++;
		}
		cout << n << ':' << ans << ',' << counter << endl;
		cout << (ans*2)/counter << endl;
	}
}
