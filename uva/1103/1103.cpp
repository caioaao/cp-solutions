#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll w, h, img[500][500], colors[500][500];


int hexToBin(char c){
	if(c >= '0' && c <= '9') return c-'0';
	
	switch(c){
		case 'a':
			return 10;
		break;
		case 'b':
			return 11;
		break;
		case 'c':
			return 12;
		break;
		case 'd':
			return 13;
		break;
		case 'e':
			return 14;
		break;
		case 'f':
			return 15;
	}
	return 0;
}

char chars[6] = {'W','A','K','J','S','D'};

vector<ll> hiers;
vector<char> hiChars;

int dr[4] = {-1, 1, 0, 0},
	dc[4] = { 0, 0,-1, 1};

void color(ll x, ll y, ll counter){
	queue<ii> q;
	q.push(ii(x,y));
	colors[x][y] = counter;
	while(!q.empty()){
		ii u = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			if(u.first+dr[i] < 0 || u.first+dr[i] >= h || u.second+dc[i] < 0 || u.second+dc[i] >= w) continue;
		
			if(colors[u.first+dr[i]][u.second+dc[i]] == -1 && img[u.first+dr[i]][u.second+dc[i]] == 1){
				colors[u.first+dr[i]][u.second+dc[i]] = counter;
				q.push(ii(u.first+dr[i], u.second+dc[i]));
			}
		}
	}
}

void color2(ll x, ll y){
	ll pinta = hiers.size();
	queue<ii> q;
	q.push(ii(x,y));
	colors[x][y] = pinta;
	int hiId = -1;
	bool isExt = false;
	while(!q.empty()){
		ii u = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			if(u.first+dr[i] < 0 || u.first+dr[i] >= h || u.second+dc[i] < 0 || u.second+dc[i] >= w){
				isExt = true; // Se toca a borda da imagem, eh branco externo
				continue;
			 }
			
			if(colors[u.first+dr[i]][u.second+dc[i]] == -1 && img[u.first+dr[i]][u.second+dc[i]] == 0){
				colors[u.first+dr[i]][u.second+dc[i]] = pinta;
				q.push(ii(u.first+dr[i], u.second+dc[i]));
			}
			else if(img[u.first+dr[i]][u.second+dc[i]] == 1){
				hiId = colors[u.first+dr[i]][u.second+dc[i]];
			}
		}
	}
	
	if(!isExt) hiers[hiId]++;
}

int main(){
	ios_base::sync_with_stdio(false);
	char c;
	ll caso = 1;
	while(cin >> h >> w){
		if(w == 0 && h == 0) break;
		cout << "Case " << caso++ << ": ";
		
		string line;
		
		getline(cin, line); //limpa
		
		for(int i = 0; i < h; i++){
			getline(cin, line);
			//~ cout << line << endl;
			for(int j = 0; j < w; j++){
				c = line[j];
				//~ cout << c;
				int b = hexToBin(c);
				for(int k = 0; k < 4; k++) img[i][j*4 + 3-k] = (b & (1 << k)) == 0 ? 0 : 1;
			}
			//~ cout << endl;
		}
		
		w*=4;
		
		
		//~ cout << endl;
		//~ for(int i = 0; i < h; i++){
			//~ for(int j = 0; j < w; j++){
				//~ cout << img[i][j];
			//~ }
			//~ cout << endl;
		//~ }
		
		memset(colors, -1, sizeof colors);
		
		ll hId = 0;
		
		// Counting blacks
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(colors[i][j] == -1 && img[i][j] == 1){
					color(i,j,hId++);
				}
			}
		}
		
		
		//~ cout << endl;
		//~ for(int i = 0; i < h; i++){
			//~ for(int j = 0; j < w; j++){
				//~ cout << colors[i][j];
			//~ }
			//~ cout << endl;
		//~ }
		//~ 
		
		// Counting inner whitespaces. There'll always be only one neighbor to an inner part, coloured with the letter id
		
		hiers.assign(hId,0);
		
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(colors[i][j] == -1 && img[i][j] == 0)
					color2(i,j);
		
		hiChars.assign(hId,'\0');
		for(int i = 0; i < hId; i++) hiChars[i] = chars[hiers[i]];
		sort(hiChars.begin(), hiChars.end());
		for(int i = 0; i < hId; i++) cout << hiChars[i];
		cout << '\n';
		
		//~ cout << endl;
		//~ for(int i = 0; i < h; i++){
			//~ for(int j = 0; j < w; j++){
				//~ cout << colors[i][j];
			//~ }
			//~ cout << endl;
		//~ }
	}
}
