#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> aumentos;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, m, p;
	
	cin >> n >> m >> p;
	
	aumentos.resize(n);
	for(int i, j, k = 0; k < p; k++){
		cin >> i >> j;
		aumentos[i-1].push_back(ii(j,1));
	}
	
	// O(n + p)
	for(int i = 0; i < n; i++){
		sort(aumentos[i].begin(), aumentos[i].end(), greater<ii>());
		int j = 0;
		vector<ii> v;
		while(j < (int)aumentos[i].size()){
			ii x = aumentos[i][j];
			j++;
			for(; j < (int)aumentos[i].size() && aumentos[i][j].first == x.first; j++){
				x.second++;
			}
			v.push_back(x);
			//~ cout << x.first << ',' << x.second << ' ';
		}
		//~ cout << endl;
		aumentos[i] = v;
	}

	// O(n + p)
	ll sum, lastI, lastAmt, amt;
	for(int i = 0; i < n; i++){
		if(aumentos[i].size() == 0){
			cout << m - 1 << '\n';
			continue;
		}
		
		//////////////////////////////
		// From m to aumentos[0] ou seta i0 = m
		/////////////////////////////
		if(aumentos[i][0].first < m && aumentos[i][0].second > 1){
			cout << -1 << '\n';
			continue;
		}
		lastI = lastAmt = m;
		int j = 0;
		if(aumentos[i][0].first == m){
			lastAmt += aumentos[i][0].second;
			j++;
		}
		sum = 0;
		for(; j < (int)aumentos[i].size(); j++){
			amt = aumentos[i][j].first + aumentos[i][j].second;
			if(lastI > aumentos[i][j].first + 1 || lastAmt >= amt){ // Se esta mais distante que 1 ou se a qtd eh maior ou igual q a atual
				if(lastI > aumentos[i][j].first + 1){ // Mais distante
					if( aumentos[i][j].second > 1){
						sum = -1;
						break;
					}
					sum += lastAmt - (--lastI);
					sum += lastI - aumentos[i][j].first - 1;
				}
				else{ // Qtd maior ou igual
					sum += lastAmt-amt;
				}
			}else{
				sum = -1;
				break;
			}
			
			lastI = aumentos[i][j].first;
			lastAmt = amt;
		}
		if(sum != -1 && lastI > 1){
			sum += lastAmt - (--lastI);
			sum += lastI - 1;
		}
		cout << sum << '\n';
	}
}
