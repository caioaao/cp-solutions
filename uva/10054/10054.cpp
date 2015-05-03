#include <iostream>
#include <cstring>
#include <list>
#include <map>
#include <algorithm>
#include <vector>

#define MAX_C 51

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int AdjMat[MAX_C][MAX_C];

vector<ii>beadColors;
list<int> cyc;

void EulerTour(list<int>::iterator i, int u){
	for(int v = 0; v < MAX_C; v++){
		if(AdjMat[u][v]){
			AdjMat[u][v]--;
			for(int uu = 0; uu < MAX_C; uu++){
				if(uu == u && AdjMat[v][uu]){
					AdjMat[v][uu]--;
					break;
				}
			}
			EulerTour(cyc.insert(i,u), v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int T, n;
	cin >> T;
	int beads[MAX_C];
	bool first = true;
	for (int casos = 0; casos < T; casos++)
	{
		if(!first) cout << '\n';
		first = false;
		
		cout << "Case #" << casos+1 << '\n';
		
		cin >> n;
		
		memset(AdjMat, 0, sizeof AdjMat);
		memset(beads, 0, sizeof beads);
		int a, b;
		int first = -1;
		for(int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if(first == -1) first = a;
			beads[a]++;
			beads[b]++;
			
			AdjMat[a][b]++;
			AdjMat[b][a]++;
		}
		int amts[2] = {0,0};
		for (int i = 0; i < MAX_C; i++)
		{
			amts[beads[i]%2]++;
		}
		if (amts[1] != 0)
		{
			cout << "some beads may be lost\n";
			continue;
		}
		//~ for (int i = 0; i < MAX_C; i++)
		//~ {
			//~ for(int j = 0; j < MAX_C; j++)
				//~ cout << AdjMat[i][j] << ' ';
			//~ cout << endl;
		//~ }
		
		
		cyc.clear();
		EulerTour(cyc.begin(), first);
		list<int>::iterator it = cyc.begin();
		cout << *it<< ' ';
		it++;
		for(int i = 1; it != cyc.end(); it++, i++){
			cout << *it << '\n' << *it << ' ';
		}
		cout << *(cyc.begin()) << '\n';
	}
}
