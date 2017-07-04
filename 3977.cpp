#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int cnt, SN;
vector<vector<int> > v;
vector<int> dfsn, sn;
vector<bool> finished;
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
			if(t == cur)
				break;
		}
		SN++;
	}
	return ret;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	
	while(tc--) {
		int n, m;
		scanf("%d%d", &n, &m);
		
		while(!S.empty()) S.pop();
		cnt = SN = 0;
		sn = dfsn = vector<int>(n);
		finished = vector<bool>(n, 0);
		v = vector<vector<int> >(n);
		while(m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}
		
		for(int i=0; i<n; i++)
			if(!dfsn[i])
				dfs(i);

		vector<int> ind(SN, 0);
		vector<vector<int> > g(SN);
		for(int i=0; i<n; i++) {
			for(int j=0; j<v[i].size(); j++) {
				int k = v[i][j];
				if(sn[i] != sn[k]) {
					g[sn[i]].push_back(sn[k]);
					ind[sn[k]]++;
				}
			}
		}

		queue<int> q;
		for(int i=0; i<SN; i++)
			if(!ind[i])
				q.push(i);

		if(q.size() != 1)
			puts("Confused");
		else {
			int k = q.front();
			for(int i=0; i<n; i++)
				if(sn[i] == k)
					printf("%d\n", i);
		}
		puts("");
	}
}
