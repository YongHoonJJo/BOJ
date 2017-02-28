#include <cstdio>
#include <vector>
using namespace std;

int v, e;

void dfs(vector<int> g[], bool visited[], int cur) 
{
	visited[cur] = true;
	v++;

	for(int i=0; i<g[cur].size(); i++) {
		int next = g[cur][i];
		e++;
		if(!visited[next]) {
			dfs(g, visited, next);
		}
	}
}

int main()
{
	int tc=1;

	while(1) {
		int n, m;
		scanf("%d %d", &n, &m);

		if(!n && !m) break;
		
		vector<int> g[501];
		while(m--) {
			int a, b;
			scanf("%d %d", &a, &b);

			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		int ans=0;
		bool visited[501]={0};
		for(int i=1; i<=n; i++) {
			if(!visited[i]) {
				v = e = 0;
				dfs(g, visited, i);
				
				if(v-1 == e/2) ans++;
			}
		}
		printf("Case %d: ", tc++);
		if(!ans) puts("No trees.");
		else ans > 1 ? printf("A forest of %d trees.\n", ans) : puts("There is one tree.");
	}

	return 0;
}
