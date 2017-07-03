#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN	100001

int cnt, SN, ans;
vector<vector<int> > v;
vector<bool> finished;
vector<int> sn, dfsn;
stack<int> s;

int dfs(int cur)
{
	dfsn[cur] = ++cnt;
	s.push(cur);

	int ret = dfsn[cur];
	for(int i=0; i<v[cur].size(); i++) {
		int next = v[cur][i];
		if(!dfsn[next]) ret = min(ret, dfs(next));
		else if(!finished[next]) ret = min(ret, dfsn[next]);
	}

	if(ret == dfsn[cur]) {
		while(1) {
			int t = s.top();
			s.pop();
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
		int i, n, m;
		scanf("%d%d",&n, &m);

		SN = ans = cnt = 0;
		v = vector<vector<int> >(n+1);
		finished = vector<bool>(n+1, 0);
		sn = dfsn = vector<int>(n+1, 0);
		while(!s.empty()) s.pop();
		
		while(m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}

		for(int i=1; i<=n; i++) {
			if(!dfsn[i])
				dfs(i);
		}

		// 간선 i->k에 대해, i와 k가 다른 scc에 속하면
		// k가 속한 scc의 ind++
		int ind[MAXN] = {0};
		for(i=1; i<=n; i++) {
			for(int j=0; j<v[i].size(); j++) {
				int k = v[i][j];
				if(sn[i] != sn[k]) 
					ind[sn[k]]++;
			}
		}
		
		
		for(i=0; i<SN; i++)
			if(!ind[i])
				ans++;

		printf("%d\n", ans);
	}	
}
