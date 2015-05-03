#include <bits/stdc++.h>

#define MAX_N 31
#define MAX_S 6010

using namespace std;

vector<int> vals, negs;
int mai, men, n;

int cnt;
bool used[MAX_S], memo[MAX_N][MAX_S][MAX_N];

void dp(int id, int soma, int amt_opened){
  if(id == n){
    if(!used[soma + 3000]){
      cnt++;
      //~ cout << soma << endl;
    }
    used[soma + 3000] = 1;
    return ;
  }
  
  if(memo[id][soma + 3000][amt_opened]) return;
  
  memo[id][soma + 3000][amt_opened] = 1;
    // fechando i parentesis
  for(int i = 0; i <= amt_opened; i++){      
    if(negs[id]){
      if((amt_opened-i) % 2 == 0){
        dp(id+1, soma - vals[id], amt_opened - i);
        
        // abrindo um parentesis depois do sinal
        dp(id+1, soma - vals[id], amt_opened - i + 1);
      }
      else{
        dp(id+1, soma + vals[id], amt_opened-i);
        
        // abrindo um parentesis depois do sinal
        dp(id+1, soma + vals[id], amt_opened - i + 1);
      }
    }
    else{
      if((amt_opened - i) % 2 == 0) dp(id+1, soma + vals[id], amt_opened-i);
      else dp(id+1, soma - vals[id], amt_opened-i);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  
  stringstream buff;
  string linha;
  while(getline(cin, linha)){
    int aux;
    char sign;
    
    vals.clear();
    negs.clear();
    buff.clear();
    buff.str(linha);
    buff >> aux;
    mai = 0, men = 0;
    while(buff >> sign >> aux){
      vals.push_back(aux);
      mai += aux;
      men -= aux;
      negs.push_back(sign == '-');
    }
    n = vals.size();
    memset(memo, 0, sizeof memo);
    memset(used, 0, sizeof used);
    cnt = 0;
    dp(0,0,0);
    cout << cnt << '\n';
  }
}
