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
	int ret = dfsn[cur] = ++cnt;
	S.push(cur);

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
	while(1) {
		int n, e;
		scanf("%d", &n);
		if(!n) break;
		scanf("%d", &e);

		cnt = SN = 0;
		finished = vector<bool>(n+1);
		sn = dfsn = vector<int>(n+1);
		v = vector<vector<int> >(n+1);

		while(e--) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}

		for(int i=1; i<=n; i++) {
			if(!dfsn[i])
				dfs(i);
		}

		vector<int> outd(SN, 0);
		for(int i=1; i<=n; i++) {
			for(int j=0; j<v[i].size(); j++) {
				int k = v[i][j];
				if(sn[i] != sn[k])
					outd[sn[i]]++;
			}
		}

		for(int i=1; i<=n; i++) {
			if(!outd[sn[i]])
				printf("%d ", i);
		}
		puts("");
	}
}
