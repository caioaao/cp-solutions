#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> > adj;
vector<int> deleted;
vector<int> cnt;

void dfs(int v, int p)
{
	deleted[v] = 1;
	for(int i = 0; i < (int)adj[v].size(); ++i)
	{
		if(p != adj[v][i] && adj[adj[v][i]].size() < 3)
			dfs(adj[v][i],v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	adj.assign(n, vector<int>());
	deleted.assign(n, 0);
	cnt.assign(n, 0);
	
	int a, b;
	for(int i = 0; i < n - 1; ++i)
	{	
		cin >> a >> b;
		--a,--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; ++i)
	{
		if(adj[i].size() <= 1) dfs(i,-1);
	}
	
	for(int u = 0; u < n; ++u)if(!deleted[u])
	{
		for(int i = 0; i < (int)adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if(deleted[v]) ++cnt[u];
		}
	}
	int u;
	for(u = 0; u < n; ++u) if(!deleted[u])
	{
		int amt = 0;
		for(int i = 0; i < (int)adj[u].size(); ++i)
		{
			int v = adj[u][i];
			amt += ((!deleted[v]) && (adj[v].size() - min(2,cnt[v]) > 1));
		}
		if(amt > 2) break;
	}
	if(u < n) cout << "No\n";
	else cout << "Yes\n";
}