#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int cnt, SN;
vector<int> dfsn, sn;
vector<bool> finished;
vector<vector<int> > v, scc;
stack<int> S;

int op(int x)
{
	return x <= n ? x+n : x-n;
}

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
		vector<int> curScc;
		while(1) {
			int t = S.top();
			S.pop();
			finished[t] = 1;
			sn[t] = SN;
			curScc.push_back(t);
			if(t == cur) break;
		}
		scc.push_back(curScc);
		SN++;
	}
	return ret;
}

int main()
{
	int ret;
	while(scanf("%d%d", &n, &m)==2) {

		cnt = SN = 0;
		scc.clear();
		dfsn = sn = vector<int>(n*2+1);
		finished = vector<bool>(n*2+1);
		v = vector<vector<int> >(n*2+1);

		for(int i=0; i<m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			if(a < 0) a = (a*-1)+n;
			if(b < 0) b = (b*-1)+n;
			v[op(a)].push_back(b);
			v[op(b)].push_back(a);
		}

		for(int i=1; i<=n*2; i++)
			if(!dfsn[i])
				dfs(i);

		int no = 0;
		for(int i=1; i<=n; i++) {
			if(sn[i] == sn[i+n]) {
				puts("no");
				no = 1;
				break;
			}
		}
		if(!no) {
			vector<int> ans(n*2+1, -1);
			queue<int> q;
			for(int i=SN-1; i>=0; i--) {
				for(int j=0; j<scc[i].size(); j++) {
					q.push(scc[i][j]);
				}
			}

			while(!q.empty()) {
				int cur = q.front();
				q.pop();
				int idx = cur <= n ? cur : cur-n;
				if(ans[idx] == -1) {
					ans[idx] = cur <= n ? 0 : 1;
				}
			}

			if(ans[1]==1) puts("yes");
			else puts("no");
		}
	}
}
