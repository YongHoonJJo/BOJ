#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct P { int a, b; };

int n, cnt, SN;
vector<int> sn, dfsn;
vector<bool> finished;
vector<vector<int> > v, scc;
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
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		scanf("%d", &n);

		scc.clear();
		cnt = SN = 0;
		finished = vector<bool>(n+1);
		sn = dfsn = vector<int>(n+1);
		v = vector<vector<int> >(n+1);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				int k;
				scanf("%1d", &k);
				if(k) v[i].push_back(j);
			}
		}

		for(int i=1; i<=n; i++)
			if(!dfsn[i])
				dfs(i);
		
		vector<vector<bool> > g(SN, vector<bool>(SN, 0));
		for(int i=1; i<=n; i++) {
			for(int j=0; j<v[i].size(); j++) {
				int k = v[i][j];
				if(sn[i] != sn[k]) {
					g[sn[i]][sn[k]] = 1;
				}
			}
		}
		
		for(int k=0; k<SN; k++) {
			for(int i=0; i<SN; i++) {
				for(int j=0; j<SN; j++) {
					if(g[i][j] && g[i][k] && g[k][j])
						g[i][j] = 0;
				}
			}
		}
			
		vector<P> ans;	
		for(int i=0; i<SN; i++) {
			int sz = scc[i].size();
			if(sz > 1) {
				for(int j=0; j<sz; j++) {
					ans.push_back((P){scc[i][j], scc[i][(j+1)%sz]});
				}
			}
		}

		for(int i=0; i<SN; i++) {
			for(int j=0; j<SN; j++) {
				if(g[i][j]) 
					ans.push_back((P){scc[i][0], scc[j][0]});
			}
		}

		int sz = ans.size();
		printf("%d\n", sz);
		for(int i=0; i<sz; i++)
			printf("%d %d\n", ans[i].a, ans[i].b);
		puts("");
	}
}
