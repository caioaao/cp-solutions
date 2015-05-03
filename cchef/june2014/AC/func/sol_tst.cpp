#include<cstdio>
#include<cmath>
#define f(i,n)    for(long long int i=0;i<n;i++)
#define llu       long long int
#define M         1000000007
#define D         60
using namespace std;
llu o[60] = {-1,1000000000,1000000,31622,3981,1000,372,177,100,63,43,31,24,19,15,13,11,
10,8,7,7,6,6,5,5,4,4,4,4,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1};

llu binpow (llu a, int n)// a^n, where a is int.
{
	llu res = 1;
	while (n) 
    {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

llu nthroot_binarysearch(llu x,int n,llu min, llu max)
{
    if(binpow(max,n)<=x)
    return max;
    llu mid=(min+max)/2;
    llu midpow=binpow(mid,n);
    while(min+1<max)
    {if(midpow==x)
     break;
     else if(midpow>x)
     max=mid;
     else min=mid;
     mid=(min+max)/2;
     midpow=binpow(mid,n);
    }
	return mid;
}

llu nthroot_newton(llu a, llu k,llu x) {
    llu y = ((k-1)*x + a/binpow(x,(k-1)))/k;
    do {
        x = y;
        y = ((k-1)*x + a/binpow(x,(k-1)))/k;
    }while(y < x);
    return x;
}

int main()
{
    llu t,n,q;
    scanf("%lld", &t);
    f(h,t)
    {
          scanf("%lld %lld", &n, &q);
          llu r,rold,ans,x,temp,a[D]={0},c=0;
          f(i,n) 
          {if(i<D)
           {scanf("%lld",&a[i]);
            a[i]=(a[i])%M;
            c=(c+a[i])%M;
           }
           else
           {scanf("%lld",&temp);
            c=(c+temp)%M;
           }
          }
          f(i,q)
          {scanf("%lld",&x);
           ans=0;
           r=x%M;
           int j=1;
           rold=x<o[j]?x:o[j];
           while(r>1)
           {ans=(ans+((r-1)*a[j-1])%M)%M;
            //r=nthroot_newton(x,j+1,rold);
            r=nthroot_binarysearch(x,j+1,1,rold);
            rold=r<o[++j]?r:o[j];
           }
           printf("%lld ",((ans+c)%M + M)%M);
          }
          printf("\n");
    }
    return 0;
}
