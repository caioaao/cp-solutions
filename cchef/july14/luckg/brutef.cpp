#include <bits/stdc++.h>

using namespace std;

bool eval(vector<int> teste){
  int soma = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 4; j < 8; j++) soma += teste[i] > teste[j];
  }
  if(soma <= 8)
    return false; 
    
  soma = 0;
  for(int i = 4; i < 8; i++){
    for(int j = 8; j < 12; j++) soma += teste[i] > teste[j];
  }
  if(soma <= 8)
    return false; 
  soma = 0;
  for(int i = 8; i < 12; i++){
    for(int j = 0; j < 4; j++) soma += teste[i] > teste[j];
  }
  if(soma <= 8)
    return false; 
  return true;
}

int main(){
  vector<int> seq(12,0);
  for(int i = 0; i < 12; i++) seq[i] = i+1;
  
  do{
    if(eval(seq)){
      vector<int> s1(seq.begin(),seq.begin()+4), s2(seq.begin()+4,seq.begin()+8), s3(seq.begin()+8,seq.end());
      sort(s1.begin(), s1.end());
      sort(s2.begin(), s2.end());
      sort(s3.begin(), s3.end());
      for(int i = 0; i < (int)s1.size(); i++) cout << s1[i] << ' ';
      cout << endl;
      for(int i = 0; i < (int)s2.size(); i++) cout << s2[i] << ' ';
      cout << endl;
      for(int i = 0; i < (int)s3.size(); i++) cout << s3[i] << ' ';
      cout << endl;
      cout << endl;
      //~ break;
    }
  }while(next_permutation(seq.begin(), seq.end()));
}


