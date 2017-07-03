#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int v, e, cnt;
int SN, sn[10001], dfsn[10001];
bool finished[10001];
vector<int> g[10001];
vector<vector<int> > scc;
stack<int> s;

int dfs(int cur)
{
	dfsn[cur] = ++cnt;	
	s.push(cur);

	int result = dfsn[cur];
	for(int i=0; i<g[cur].size(); i++) {
		int next = g[cur][i];
		if(!dfsn[next]) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}

	if(result == dfsn[cur]) {
		int t;
		vector<int> curScc;
		do {
			t = s.top();
			s.pop();
			curScc.push_back(t);
			finished[t] = true;
			sn[t] = SN;
		} while(t != cur);

		sort(curScc.begin(), curScc.end());
		scc.push_back(curScc);
		SN++;
	}
	
	return result;
}

int main()
{
	scanf("%d%d", &v, &e);
	while(e--) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
	}

	for(int i=1; i<=v; i++)
		if(!dfsn[i])
			dfs(i);
		
	sort(scc.begin(), scc.end());

	printf("%d\n", SN);
	for(int i=0; i<scc.size(); i++) {
		for(int j=0; j<scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		puts("-1");
	}
}
