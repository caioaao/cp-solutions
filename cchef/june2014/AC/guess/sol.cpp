#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b,a%b); }

inline pll reduct(pll ret){
  ll aux = gcd(max(ret.first, ret.second), min(ret.first, ret.second));
    
  
  ret.first /= aux;
  ret.second /= aux;
  
  return ret;
}

inline pll mult(pll a, pll b){
  pll ret(a.first*b.first, a.second * b.second);
  
  return ret;
}

inline pll sum(pll a, pll b){
  pll ret(a.first + b.first, a.second);
  return reduct(ret);
}


int main(){
  ios_base::sync_with_stdio(false);
  ll t, n, m;
  pll n_o, n_e, m_o, m_e, ans;
  cin >> t;
  while(t--){
    cin >> n >> m;
    
    n_o.second = n_e.second = n;
    m_o.second = m_e.second = m;
    
    n_e.first = n/2;
    n_o.first = n - n_e.first;
    
    m_e.first = m/2;
    m_o.first = m - m_e.first;
    
    ans = sum(mult(n_e,m_o), mult(n_o,m_e));
    cout << ans.first << '/' << ans.second << '\n';
    
    //~ pll conf = sum(ans,sum(mult(n_o,m_o), mult(n_e,m_e)));
    //~ cout << conf.first << '/' << conf.second << endl;
  }
}
