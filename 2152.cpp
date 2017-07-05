#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, s, t;
int cnt, SN;
vector<vector<int> > g, v;
vector<int> dfsn, sn, city, ind;
vector<bool> finished, visited;
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
			finished[t] = 1;
			sn[t] = SN;
			if(t == cur) break;
		}		
		SN++;
	}
	return ret;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);

	finished = vector<bool>(n+1);
	sn = dfsn = vector<int>(n+1);
	v = vector<vector<int> >(n+1);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
	}

	for(int i=1; i<=n; i++)
		if(!dfsn[i])
			dfs(i);

	visited = vector<bool>(SN);
	ind = city = vector<int>(SN, 0);
	g = vector<vector<int> >(SN);
	for(int i=1; i<=n; i++) {
		city[sn[i]]++;
		for(int j=0; j<v[i].size(); j++) {
			int k = v[i][j];
			if(sn[i] != sn[k]) {
				g[sn[i]].push_back(sn[k]);
				ind[sn[k]]++;
			}
		}		
	}
	
	s = sn[s];
	t = sn[t];

	vector<int> sMax(SN, 0);
	queue<int> q;
	for(int i=0; i<SN; i++) {
		sMax[i] = city[i];	
		if(!ind[i])
			q.push(i);
	}

	visited[s] = 1; // ind[i]와 관계없이 s를 방문한 것으로 처리
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for(int i=0; i<g[cur].size(); i++) {
			int next = g[cur][i];
			if(visited[cur]) {
				sMax[next] = max(sMax[next], sMax[cur]+city[next]);
				visited[next] = 1;
			}
			if(--ind[next]==0) q.push(next);
		}
	}
	printf("%d\n", visited[t] ? sMax[t] : 0);
}
