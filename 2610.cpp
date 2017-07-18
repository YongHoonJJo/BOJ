#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF	1000000000

int n, m;
int g[101][101], group[101];

void dfs(int x, int k)
{
	int i;
	group[x] = k;

	for(i=1; i<=n; i++) {
		if(g[x][i] == 1 && !group[i])
			dfs(i, k);
	}
}

int main()
{
	int i, j, k, cnt=0;
	scanf("%d%d", &n, &m);

	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			g[i][j] = (i==j ? 0 : INF);

	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}

	for(i=1; i<=n; i++) {
		if(!group[i])
			dfs(i, ++cnt);
	}
	printf("%d\n", cnt);	

	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);

	vector<int> size(cnt+1, INF);
	vector<int> ans(cnt);
	for(i=1; i<=n; i++) {
		int dist = 0;
		for(j=1; j<=n; j++) {
			if(g[i][j] != INF && dist < g[i][j])
				dist = g[i][j];
		}
		if(size[group[i]] > dist) {
			size[group[i]] = dist;
			ans[group[i]-1] = i;
		}
	}

	sort(ans.begin(), ans.end());	
	for(i=0; i<cnt; i++)
		printf("%d\n", ans[i]);
}
