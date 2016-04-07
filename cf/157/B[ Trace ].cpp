#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

#define vpi vector<int>::iterator
#define ll long long int

int main(){
	int n, r;
	vector <int> raios;


	bool red = true;
	
	scanf("%d\n",&n);

	while(n--){
		scanf("%d ", &r);
		raios.push_back(r*r);
	}

	sort(raios.begin(), raios.end());

	for(vpi ii = raios.end()-1; ii!= raios.begin()-1; --ii){
		if(!red) *ii = -(*ii);
		red = !red;
	}
	if(*(raios.end()-1) < 0){
		raios.pop_back();
	}

	ll ans = accumulate(raios.begin(),raios.end(), 0);

	printf("%.8f", (ans*3.1415926536));
}