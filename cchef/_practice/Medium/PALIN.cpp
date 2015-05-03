#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int to_int(char letra){
    switch(letra){
        case '0':
             return 0;
        case '1':
             return 1;
        case '2':
             return 2;
        case '3':
             return 3;
        case '4':
             return 4;
        case '5':
             return 5;
        case '6':
             return 6;
        case '7':
             return 7;
        case '8':
             return 8;
        case '9':
             return 9;
    }
}

void espelho(string &n){
    char conv1, conv2;
    int x_max,n_int1,n_int2, k;
    double n_double;
    k = n.length()-1;
    
    if(k == 1) x_max = 0;
    else x_max = (k+1)/2;
    
    bool teste = false;
    int x = x_max;
    for(; x >= 0; x--){
        n_int1 = to_int(n[x]);
        n_int2 = to_int(n[k-x]);
        if(n_int1 < n_int2){
            teste = true;
            break;
        }else{
            n[k-x] = n[x];
        }
    }
    if(teste){
        if(n.length()%2 != 0){
            if(x == x_max-1){
              // x++;
            }
        }
        n[k-(x+1)]++;
        for(int i = k; i>x; i--){
            n[k-i] = '0';
        }
        espelho(n);
    }
}

int main(){
   int t;
   cin >> t;
   for(int contador = 0; contador < t; contador++){
       int k = 0;
       string n;
       
       cin >> n;

       k = n.length();
       int ene = atoi(n.c_str());
       ene++;
       char n_buf[8];
       memset(n_buf,'\0',8);
       sprintf(n_buf,"%d",ene);
       n = n_buf;
       
       if(k>0){
           k--;
           espelho(n);
       }
       
       cout << n << endl;
       
   }
}
