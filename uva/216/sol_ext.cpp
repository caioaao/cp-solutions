// @BEGIN_OF_SOURCE_CODE
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
#define INT_MAX 1e9
using namespace std;
 
 
int main ()
{
    int n;
    int cases = 0;
 
    while ( scanf ("%d", &n) && n ) {
        int permute [8] = {0, 1, 2, 3, 4, 5, 6, 7};
        int x [10];
        int y [10];
        int dummyX [10];
        int dummyY [10];
 
        for ( int i = 0; i < n; i++ ) {
            scanf ("%d %d", &x [i], &y [i]);
            dummyX [i] = x [i];
            dummyY [i] = y [i];
        }
 
        double minDistance = INT_MAX;
        int dummy [8];
 
        do {
            double calculateDistance = 0;
 
            for ( int i = 0; i < n; i++ ) {
                x [i] = dummyX [permute [i]];
                y [i] = dummyY [permute [i]];
            }
 
            for ( int i = 1; i < n; i++ ) {
                calculateDistance += sqrt ((x [i - 1] - x [i]) * (x [i - 1] - x [i]) + (y [i - 1] - y [i]) * (y [i - 1] - y [i]) );
            }
 
            if ( calculateDistance < minDistance ) {
                minDistance = calculateDistance;
                for ( int i = 0; i < n; i++ )
                    dummy [i] = permute [i];
            }
        } while ( next_permutation (permute, permute + n) );
 
        for ( int i = 0; i < n; i++ ) {
            x [i] = dummyX [dummy [i]];
            y [i] = dummyY [dummy [i]];
        }
 
        // print output
        printf ("**********************************************************\n");
        printf ("Network #%d\n", ++cases);
        double total = 0;
        for ( int i = 1; i < n; i++ ) {
            double d = sqrt ((x [i - 1] - x [i]) * (x [i - 1] - x [i]) + (y [i - 1] - y [i]) * (y [i - 1] - y [i]) );
            d += 16;
            printf ("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x [i - 1], y [i - 1], x [i], y [i], d);
            total += d;
        }
        printf ("Number of feet of cable required is %.2lf.\n", total);
    }
 
 
    return 0;
}
