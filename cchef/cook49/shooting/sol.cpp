#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


char ma[55][55];
int n,m;

//~ set<vector<bool> > memo[55][55][2][2];

bool dp(int i, int j, bool limpouR, bool temE, ll colLimpas){
  if(j == 0 && temE) return false;
  if(i == -1) return true;
  if(j == 0) limpouR = 0;
  
  //~ cout << i << ' ' << j << ' ' << limpouR << ' ' << temE << ' ' << colLimpas[j] << '\n';
  
  //~ if(memo[i][j][limpouR][temE].count(colLimpas)) return false;
  
  //~ memo[i][j][limpouR][temE].insert(colLimpas);
  
  
  int ni, nj;
  if(j + 1 == m) {
    ni = i-1;
    nj = 0;
  }
  else{
    ni = i;
    nj = j+1;
  }
  
  if(ma[i][j] == '.') return dp(ni,nj,limpouR, temE, colLimpas);
  if(ma[i][j] == 'E'){
    bool nE = temE;
    if(!limpouR && !(colLimpas&(1<<j))) nE = 1;
    
    return dp(ni,nj,limpouR, nE, colLimpas);
  }
  
  
  
  return dp(ni,nj, limpouR, temE, colLimpas|(1<<j)) ||
	 dp(ni,nj, limpouR,    0, colLimpas	  ) ||
	 dp(ni,nj, 1	  , temE, colLimpas	  );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
	cin >> ma[i][j];
      }
      
    //~ for(int i = 0; i < n; i++){
      //~ for(int j = 0; j < m; j++){
	//~ for(int k = 0; k < 2; k++){
	  //~ for(int l = 0; l < 2; l++){
	    //~ memo[i][j][k][l].clear();
	  //~ }
	//~ }
      //~ }
    //~ }
    
    if(dp(n-1,0,0,0,0)) cout << "Possible\n";
    else cout << "Impossible\n";
  }
}
