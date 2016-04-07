#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

inline int get_ci(char c){
  if(c == &#39;R&#39;) return 0;
  if(c == &#39;G&#39;) return 1;
  if(c == &#39;B&#39;) return 2;
  if(c == &#39;Y&#39;) return 3;
  if(c == &#39;W&#39;) return 4;
  return -1;
}

inline int numOfOnes(int i){
i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

vii cards;
set<ii> ucards;
int main(){
  ios_base::sync_with_stdio(false);
  int n;
  string s;
  while(cin >> n){

    int c, id;
    
    cards.clear();
    ucards.clear();
    for(int i = 0; i < n; i++){
      cin >> s;
      c = get_ci(s[0]);
      id = s[1] - &#39;1&#39;;
      if(!ucards.count(ii(c,id))) cards.push_back(ii(c,id));
      ucards.insert(ii(c,id));
    }
    
    int ans = 10;
    
    for(int tips = 0; tips < (1 << 10); tips++){
      bool allOk = true;
      for(int i = 0; i < (int)cards.size(); i++){
        for(int j = i+1; j < (int)cards.size(); j++){
          if(!((cards[i].first != cards[j].first && (((tips & (1 << cards[i].first)) != 0) || ((tips & (1 << cards[j].first)) != 0))) ||
                (cards[i].second != cards[j].second && (((tips & (1 << (cards[i].second + 5))) != 0) || ((tips & (1 << (cards[j].second + 5))) != 0))))){
            allOk = false;
            goto caboLp;
          }
        }
      }
      caboLp:
      if(allOk){
        ans = min(ans, numOfOnes(tips));
      }
    }
    //~ cout << maxMatching() << &#39;\n&#39;;
    cout << ans << &#39;\n&#39;;
  }
}
