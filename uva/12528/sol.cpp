#include <bits/stdc++.h>

using namespace std;

int p1[10],q1[10],p2[10],q2[10];

int W, D, A, k;
double mi;

const double eps = 1e-6, epsb = 1e-7;

inline double f1(double x){
  double num = 0, den = 0;
  for(int i = 0; i < k; i++){
    num += p1[i]*pow(x,i);
    den += q1[i]*pow(x,i);
  }
  return num/den > mi ? num/den : mi;
}

inline double simps1(double a, double b) {
  return (f1(a) + 4*f1((a+b)/2) + f1(b))*(b-a)/6;
}

double integrate1(double a, double b){
  double m = (a+b)/2;
  double l = simps1(a,m), r = simps1(m,b), tot=simps1(a,b);
  if (fabs(l+r-tot) < eps) return tot;
  return integrate1(a,m)+integrate1(m,b);
}

double f2(double x){
  double num = 0, den = 0;
  for(int i = 0; i < k; i++){
    num += p2[i]*pow(x,i);
    den += q2[i]*pow(x,i);
  }
  return num/den > mi ? num/den : mi;
}

double simps2(double a, double b) {
  return (f2(a) + 4*f2((a+b)/2) + f2(b))*(b-a)/6;
}

double integrate2(double a, double b){
  double m = (a+b)/2;
  double l = simps2(a,m), r = simps2(m,b), tot=simps2(a,b);
  if (fabs(l+r-tot) < eps) return tot;
  return integrate2(a,m)+integrate2(m,b);
}

int main(){
  
  while(scanf("%d %d %d %d", &W, &D, &A, &k) != EOF){
    k++;
    for(int i = 0; i < k; i++) scanf("%d", p1 + i);
    for(int i = 0; i < k; i++) scanf("%d", q1 + i);
    for(int i = 0; i < k; i++) scanf("%d", p2 + i);
    for(int i = 0; i < k; i++) scanf("%d", q2 + i);
    
    double lo = -D, hi = 0;
    while(hi - lo > epsb){
      mi = (hi + lo)/2;
      if(integrate1(0,W) - integrate2(0,W) > A){
        lo = mi;
      }
      else{
        hi = mi;
      }
    }
    printf("%.5lf\n",-mi);
  } 
}
