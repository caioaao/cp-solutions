#include <iostream>
#include <bitset>

using namespace std;

bitset<1000001> tempo;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, start, end, rep;
	cin >> n >> m;
	bool conflict;
	while(n!= 0 || m != 0){
		tempo.reset();
		conflict = false;
		for(int it = 0; it < n; it++){
			cin >> start >> end;
			if(conflict) continue;
			
			for(int i = start+1; i <= end; i++){
				if(tempo.test(i)){
					conflict = true; break;
				}
				tempo.set(i);
			}
		}
		
		for(int it = 0; it < m; it++){
			cin >> start >> end >> rep;
			if(conflict) continue;
			for(int i = start; i < 1000001; i+=rep){
				for(int j = 1; j <= end-start && i+j < 1000001; j++){					
					if(tempo.test(i+j)){
						conflict = true; break;
					}
					tempo.set(i+j);
				}
			}
		}
		cout << (conflict ? "CONFLICT\n" : "NO CONFLICT\n");
		
		cin >> n >> m;
	}
}
