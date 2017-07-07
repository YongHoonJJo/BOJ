#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int cnt, SN;
vector<vector<int> > v;
vector<int> sn, cost, dfsn;
vector<bool> rest, finished;
stack<int> S;

int dfs(int cur)
{
	dfsn[cur] = ++cnt;
	S.push(cur);

	int ret = dfsn[cur];
	for(int i=0; i<v[cur].size(); i++) {
		int next = v[cur][i];
		if(!dfsn[next]) ret = min(ret, dfs(next));
		else if(!finished[next]) ret = min(ret, dfsn[next]);
	}

	if(ret == dfsn[cur]) {
		while(1) {
			int t = S.top();
			S.pop();
			sn[t] = SN;
			finished[t] = 1;
			if(t == cur) break;
		}
		SN++;
	}
	return ret;
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	
	dfsn = sn = cost = vector<int>(n+1);
	finished = rest = vector<bool>(n+1);
	v = vector<vector<int> >(n+1);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
	}

	for(int i=1; i<=n; i++)
		scanf("%d", &cost[i]);

	int s, p;
	scanf("%d%d", &s, &p);
	while(p--) {
		int k;
		scanf("%d", &k);
		rest[k] = 1;
	}

	for(int i=1; i<=n; i++)
		if(!dfsn[i])
			dfs(i);

	// graph reModeling
	s = sn[s];
	vector<vector<int> > g(SN);
	vector<int> nRest, ATM(SN, 0), ind(SN, 0);
	for(int cur=1; cur<=n; cur++)	{
		ATM[sn[cur]] += cost[cur];
		if(rest[cur]) {
			nRest.push_back(sn[cur]);
		}
		
		for(int i=0; i<v[cur].size(); i++) {
			int next = v[cur][i];
			if(sn[cur] != sn[next]) {
				g[sn[cur]].push_back(sn[next]);
				ind[sn[next]]++;
			}
		}
	}

	queue<int> q;
	vector<int> dist(SN, 0);
	vector<bool> visited(SN, 0); 
	for(int i=0; i<SN; i++) {
		dist[i] = ATM[i];
		if(!ind[i])
			q.push(i);
	}

	visited[s] = 1;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
	
		for(int i=0; i<g[cur].size(); i++) {
			int next = g[cur][i];
			if(visited[cur]) {
				dist[next] = max(dist[next], dist[cur]+ATM[next]);
				visited[next] = 1;
			}
			if(--ind[next]==0)
				q.push(next);
		}
	}
	
	int ans=0;
	for(int i=0; i<nRest.size(); i++) {
		ans = max(ans, dist[nRest[i]]);
	}

	printf("%d\n", ans);
}
