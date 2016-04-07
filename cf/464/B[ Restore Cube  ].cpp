#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

inline ll dist2(ll ax,ll ay,ll az,ll bx,ll by,ll bz){
  return (ax-bx)*(ax-bx) + (ay-by)*(ay-by) + (az-bz)*(az-bz);
}

ll ori[8][3];
ll d[3], cn[3], in[3], x;

bool cmp(int a, int b){
  return d[a] < d[b];
}

bool test(){
  cn[0] = cn[1] = cn[2] = 0;
  for(int i = 0; i < 8; i++){
    for(int j = i+1; j < 8; j++){
      x = dist2(ori[i][0],ori[i][1],ori[i][2],ori[j][0],ori[j][1],ori[j][2]);
      //~ cout << ori[i][0] << &#39;,&#39; << ori[i][1] << &#39;,&#39; << ori[i][2] << " to "  << ori[j][0] << &#39;,&#39; << ori[j][1] << &#39;,&#39; << ori[j][2] << ": " << x << &#39;\n&#39;;
      int k = 0;
      for(; k < 3; k++){
        if(d[k] == x || !cn[k]){
          d[k] = x;
          cn[k]++;
          break;
        }
      }
      if(k == 3) return false;
    }
  }
  in[0] = 0;
  in[1] = 1;
  in[2] = 2;
  sort(in,in+3,cmp);
  return cn[in[0]] == 12 && cn[in[1]] == 12 && cn[in[2]] == 4 && 
    d[in[0]]*2 == d[in[1]] && d[in[0]]*3 == d[in[2]]; 
}
bool bt(int id){
  if(id == 8){
    return test();
  }
  
  do{
    if(bt(id+1)) return true;
  }
  while(next_permutation(ori[id],ori[id]+3));
  return false;
}

int main(){
  //~ for(int i = 0; i < 8; i++)
  //~ for(int j = 0; j < 3; j++)
    //~ cin >> ori[i][j];
  //~ cout << test();
  
  ios_base::sync_with_stdio(false);
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 3; j++)
      cin >> ori[i][j];
    sort(ori[i],ori[i]+3);
  }
  if(bt(0)){
    cout << "YES\n";
    for(int i = 0; i < 8; i++)
      cout << ori[i][0] << &#39; &#39; << ori[i][1] << &#39; &#39; << ori[i][2] << &#39;\n&#39;;
  }
  else{
    cout << "NO\n";
  }
}
