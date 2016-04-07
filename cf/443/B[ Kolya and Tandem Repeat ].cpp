#include <bits/stdc++.h>

#define MAX_N 401
#define MAX_L 201

using namespace std;

string str;
int k, memo[MAX_N][MAX_L], n;

int main(){
  ios_base::sync_with_stdio(false);
  string dummy;
  while(getline(cin,str)){
    cin >> k;
    n = str.size();
    
    for(int i = 0; i <= (n+k)/2; i++){
      memo[n+k][i] = 0;
    }
    int ans = 0;
    for(int i = n+k - 1; i >= 0; i--){
      for(int j = 1; j <= (n+k)/2; j++){
	if(i+j < n+k && ((i < n && (i+j >= n || str[i+j] == str[i])) || (i >= n))){ // matches
	  memo[i][j] = memo[i+1][j] + 1;
	}
	else{
	  memo[i][j] = 0;
	}
	if(memo[i][j] == j) ans = max(ans,j);
      }
    }
    
    cout << ans*2 << &#39;\n&#39;;
    
    getline(cin,dummy);
  }
}
