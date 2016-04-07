#include <iostream>
#include <map>

using namespace std;
map<int,int> perm;

int main(){
    int n, fixed = 0, a, permr = 0;
cin >> n;
    for(int i = 0; i < n; i++){
            cin >> a;
            if(a == i) fixed++;
            else{
                 if(perm.find(a)->second == i) permr = 2;
                 else permr = 1;
                 perm[i] = a;
            }
    }
    for(map<int,int>::const_iterator ii = perm.begin(); ii != perm.end(); ++ii){
                                     if(permr==2) break;
                                     if(perm[ii->second] == ii->first){
                                                        permr=2;
                                     }
    }
    cout << fixed+permr;
    
}
