#include <bits/stdc++.h>

#define MAXX 10000000000ll
#define eps 1e-6

using namespace std;
typedef long long ll;
typedef double ld;

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////typedef long double ld;
typedef complex<ld> base;

const double PI = acos(-1.0);

void fft (vector<base> & a, bool invert)
{
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		ld ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res)
{
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

ll n, s;
vector<ll> S;
bool a[18000000+10], b[18000000+10];
int calc1(){
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  
  S.assign(n,0);
  ll x;
  scanf("%lld",&x);
  S[0] = x;
  int num1 = (S[0]%17999987LL);
  int num2 = (S[0]%19999999LL);
  int ans = 1;
  a[num1] = 1;
  b[num2] = 1;
  for(int i = 1; i < n; i++){
    scanf("%lld",&x);
    
    S[i] = S[i-1] + x;
    
    num1 = (S[i]%17999987LL);
    num2 = (S[i]%19999999LL);
    
    if(!a[num1] || !b[num2]){
      ans++;
      
      a[num1] = 1;
      b[num2] = 1;
    }
    
    for(int j = 0; j < i; j++){
      num1 = ((S[i]-S[j])%17999987LL);
      num2 = ((S[i]-S[j])%19999999LL);
        
      if(!a[num1] || !b[num2]){
        ans++;
        
        a[num1] = 1;
        b[num2] = 1;
      }
    }
  }
  return ans-1;
}

bool *lkptbl;
int calc2(){
  S.assign(n,0);
  lkptbl = new bool[20000010];
  int x;
  scanf("%d",&x);
  S[0] = x;
  lkptbl[S[0]] = 1;
  int ret = 1;
  for(int i = 1; i < n; i++){
    scanf("%d",&x);
    S[i] = S[i-1] + x;
    if(!lkptbl[S[i]]) ret++;
    lkptbl[S[i]] = 1;
    for(int j = 0; j < i; j++){       
      if(!lkptbl[S[i] - S[j]]) ret++;
      lkptbl[S[i] - S[j]] = 1;
    }
  }
  
  return ret-1;
}
vector<int> A,B,C;
int calc3(){
  S.assign(n,0);
  int x;
  scanf("%d",&x);
  S[0] = x;
  for(int i = 1; i < n; i++){
    scanf("%d",&x);
    S[i] = S[i-1] + x;
  }
  A.assign(2*S[n-1]+1,0);
  B.assign(2*S[n-1]+1,0);
  A[0] = B[S[n-1]] = 1;
  for(int i = 0; i < n; i++){
    ++A[S[i]];
    ++B[S[n-1] - S[i]];
  }
  multiply(A,B,C);
  int ans = 0;
  for(int i = S[n-1]+1; i < (int)C.size(); i++) ans += C[i] > 0;
  return ans-1;
}

int main(){
  
  scanf("%lld",&n);
  
  if(n <= 8000) {
    printf("%d\n", calc1());
  }
  else if(n <= 20000){
    printf("%d\n", calc2());
  }
  else{
    printf("%d\n", calc3());
  }
}
