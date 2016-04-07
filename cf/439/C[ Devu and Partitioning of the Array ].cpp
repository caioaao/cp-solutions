#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;


vi pares, impares;
vector<vi> gruposp, gruposi;


int main(){
  ios_base::sync_with_stdio(false);
  
  ll n, k, p, aux, nis, nps;
  
  while(cin >> n >> k >> p){
    if(p > 0)
      gruposp.assign(p,vi());
    if(p < k)
      gruposi.assign(k - p,vi());
    pares.clear();
    impares.clear();
    for (int i = 0; i < n; i++)
    {
      cin >> aux;
      if(aux%2 == 0) pares.push_back(aux);
      else impares.push_back(aux);
    }
    nis = impares.size();
    nps = pares.size();
    
    if(nis <  k - p){
      cout << "NO\n";
      continue;
    }
    for(int i = 0; i < k - p; i++){
      gruposi[i].push_back(impares.back());
      impares.pop_back();
    }
    
    nis = impares.size();
    
    if(nis % 2 != 0){
      cout << "NO\n";
      continue;
    }
    
    nps += nis/2;
    if(nps < p){
      cout << "NO\n";
      continue;
    }
    
    int i, k;
    
    for(i = 0, k = 0; i < p && k < nis-1; i++, k+=2){
      gruposp[i].push_back(impares[k]);
      gruposp[i].push_back(impares[k+1]);
    }
    
    // Se faltou pares
    for(; i < p && pares.size() > 0; i++){  
      gruposp[i].push_back(pares.back());
      pares.pop_back();
    }
    
    // Se sobrou impares
    if(p > 0){
      for(i = p*2; i < nis; i++){
        gruposp[0].push_back(impares[i]);
      }
      
      for(i = 0; i < (int)pares.size(); i++){
        gruposp[0].push_back(pares[i]);
      }
    }
    else{
      for(i = p*2; i < nis; i++){
        gruposi[0].push_back(impares[i]);
      }
      for(i = 0; i < (int)pares.size(); i++){
        gruposi[0].push_back(pares[i]);
      }
    }
    cout << "YES\n";
    for(int i = 0 ; i < (int)gruposp.size(); i++){
      cout << gruposp[i].size() << &#39; &#39;;
      bool first = true;
      for(int j = 0; j < (int)gruposp[i].size(); j++){
        if(!first) cout << &#39; &#39;;
        first = false;
        cout << gruposp[i][j];
      }
      cout << &#39;\n&#39;;
    }
    for(int i = 0 ; i < (int)gruposi.size(); i++){
      cout << gruposi[i].size() << &#39; &#39;;
      bool first = true;
      for(int j = 0; j < (int)gruposi[i].size(); j++){
        if(!first) cout << &#39; &#39;;
        first = false;
        cout << gruposi[i][j];
      }
      cout << &#39;\n&#39;;
    }
  }
}
