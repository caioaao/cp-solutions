#include <bits/stdc++.h>

using namespace std;

struct node{
  vector<node *> child;
  int ch_id[30], max_d;
  char letter;
  node(){
    memset(ch_id,-1,sizeof ch_id);
  }
  node(char c){
    memset(ch_id,-1,sizeof ch_id);
    letter = c;
  }
};

node * root;

bool dp(node *curr, bool turn, int d){
  //~ cout << curr->letter << &#39; &#39; << turn << &#39;,&#39; << d << &#39;\n&#39;;
  if(curr->child.size() == 0){
    //~ cout << curr->letter<< &#39; &#39; << d << &#39;,&#39;;
    return turn;
  }
  
  for(int i = 0; i < (int)curr->child.size(); i++){
    if(turn){ // vez do 2o escolher
      if(!dp(curr->child[i],!turn, d+1)) return false;
    }
    if(!turn){ // primeiro escolher
      if(dp(curr->child[i], !turn, d+1)) return true;
    }
  }
  
  return turn;
}


bool dp2(node *curr, bool turn, int d){
  //~ cout << curr->letter << &#39; &#39; << turn << &#39;,&#39; << d << &#39;\n&#39;;
  if(curr->child.size() == 0){
    return turn;
  }
  
  for(int i = 0; i < (int)curr->child.size(); i++){
    if(!turn){ // vez do 1o escolher
      if(!dp2(curr->child[i],!turn, d+1)) return false;
    }
    if(turn){ // segundo escolher
      if( dp2(curr->child[i], !turn, d+1)) return true;
    }
  }
  
  return !turn;
}

node * nd_add(node *at, char c){
  int ndid = at->ch_id[c-&#39;a&#39;];
  node * n;
  
  if(ndid != -1){
    n = at->child[ndid];
  }else{
    n = new node(c);
    at->ch_id[c-&#39;a&#39;] = ndid = at->child.size();
    at->child.push_back(n);
  }
  
  return n;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, k;
  while(cin >> n >> k){
    root = new node();
    string s;
    for(int i = 0; i < n; i++){
      cin >> s;
      
      node *curr = root;
      for(int i = 0; i < (int)s.size(); i++){
        curr = nd_add(curr, s[i]);
      }
    }
    bool w = dp(root,0,0), l = !dp2(root,0,0);

    //~ cout << w << &#39; &#39; << l << endl;

    if(w && l){
      cout << "First\n";
    }
    else if(w){
      if(k%2 == 0) cout << "Second\n";
      else cout << "First\n";
    }
    else{
      cout << "Second\n";
    }
  }
}
