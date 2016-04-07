#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	string s;
	int m, r, l, tam;
	
	vector<int> x, y, z;
	
	while(cin >> s){
		cin >> m;
		x.assign(s.size(),0);
		y.assign(s.size(),0);
		z.assign(s.size(),0);
		for(int i = 0; i < (int)s.size(); i++){
			x[i] = (i > 0 ? x[i-1] : 0 );
			y[i] = (i > 0 ? y[i-1] : 0 );
			z[i] = (i > 0 ? z[i-1] : 0 );
			switch(s[i]){
				case &#39;x&#39;:
					x[i]++;
				break;
				case &#39;y&#39;:
					y[i]++;
				break;
				case &#39;z&#39;:
					z[i]++;
			}
		}
		for(int i = 0; i < m; i++){
			cin >> r >> l;
			r--;l--;
			tam = (l-r)+1;
			if(tam < 3){
				cout << "YES\n";
				continue;
			}
			int amtX = x[l]-(r > 0 ? x[r-1] : 0), amtY = y[l]-(r > 0 ? y[r-1] : 0), amtZ = z[l]-(r > 0 ? z[r-1] : 0);
			
			// comeca com x
			if ((amtX == tam/3+(tam%3 != 0) && amtZ == (tam-1)/3+((tam-1)%3 != 0) && amtY == (tam-2)/3+((tam-2)%3 != 0)) ||
				(amtY == tam/3+(tam%3 != 0) && amtX == (tam-1)/3+((tam-1)%3 != 0) && amtZ == (tam-2)/3+((tam-2)%3 != 0)) ||
				(amtZ == tam/3+(tam%3 != 0) && amtY == (tam-1)/3+((tam-1)%3 != 0) && amtX == (tam-2)/3+((tam-2)%3 != 0))) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
