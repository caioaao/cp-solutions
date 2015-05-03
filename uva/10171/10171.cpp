#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;

int N;
vector<char> cities;
map<char,int> cities_dict;
vector<vi> AdjMatY, AdjMatM;
vector<iii> EdgeListY;
vector<iii> EdgeListM;

int main(){
	ios_base::sync_with_stdio(false);
	char age, dir, x, y;
	int w;
	while(1){
		cin >> N;
		if(N == 0) break;
		
		EdgeListY.clear();
		EdgeListM.clear();
		AdjMatY.clear();AdjMatM.clear();
		cities.clear(); cities_dict.clear();
		for(int i = 0; i < N; i++){
			cin >> age >> dir >> x >> y >> w;
			if(!cities_dict.count(x)){
				cities_dict[x] = cities.size();
				cities.push_back(x);
			}
			if(!cities_dict.count(y)){
				cities_dict[y] = cities.size();
				cities.push_back(y);
			}
			if(age == 'Y'){
				EdgeListY.push_back(iii(cities_dict[x],ii(cities_dict[y],w)));
				if(dir == 'B') EdgeListY.push_back(iii(cities_dict[y],ii(cities_dict[x],w)));
			}
			else{
				EdgeListM.push_back(iii(cities_dict[x],ii(cities_dict[y],w)));
				if(dir == 'B') EdgeListM.push_back(iii(cities_dict[y],ii(cities_dict[x],w)));
			}
		}
		
		cin >> x >> y;
		if(!cities_dict.count(x) || !cities_dict.count(y)){
			cout << "You will never meet.\n";
			continue;
		}
		
		AdjMatY.assign(cities.size(), vi(cities.size(),INF));
		AdjMatM.assign(cities.size(), vi(cities.size(),INF));
		
		for(int i = 0; i < (int)EdgeListY.size(); i++)
			AdjMatY[EdgeListY[i].first][EdgeListY[i].second.first] = EdgeListY[i].second.second;
		
		for(int i = 0; i < (int) EdgeListM.size(); i++)
			AdjMatM[EdgeListM[i].first][EdgeListM[i].second.first] = EdgeListM[i].second.second;
			
		for(int i = 0; i < (int)cities.size(); i++) AdjMatM[i][i] = AdjMatY[i][i] = 0;
		// Floyd Warshall
		for(int k = 0; k < (int)cities.size(); k++)
			for(int i = 0; i < (int)cities.size(); i++)
				for(int j = 0; j < (int)cities.size(); j++)
					AdjMatY[i][j] = min(AdjMatY[i][j],AdjMatY[i][k]+AdjMatY[k][j]);
		
		for(int k = 0; k < (int)cities.size(); k++)
			for(int i = 0; i < (int)cities.size(); i++)
				for(int j = 0; j < (int)cities.size(); j++)
					AdjMatM[i][j] = min(AdjMatM[i][j],AdjMatM[i][k]+AdjMatM[k][j]);
					
		int ans = INF;
		for(int i = 0; i < (int)cities.size(); i++) ans = min(ans, AdjMatY[cities_dict[x]][i]+AdjMatM[cities_dict[y]][i]);
		if(ans >= INF){
			cout << "You will never meet.\n";
			continue;
		}
		
		vector<char> answers;
		cout << ans;
		for(int i = 0; i < (int)cities.size(); i++){
			if(AdjMatY[cities_dict[x]][i]+AdjMatM[cities_dict[y]][i] == ans) answers.push_back(cities[i]);
		}
		sort(answers.begin(), answers.end());
		for(int i = 0; i < (int)answers.size(); i++) cout << ' ' << answers[i];
		cout << '\n';
	}
}
