#include <stdio.h>
#define MAXN	100001

int tc, cnt;
int g[MAXN];
int visited[MAXN], group[MAXN];

void dfs(int cur)
{
	int next = g[cur];
	visited[cur] = tc;

	if(visited[next] != tc)
		dfs(next);
	else {
		if(group[next] != tc) {
			int i;
			for(i=next; group[i]!=tc; i=g[i]) {
				cnt++;
				group[i] = tc;
			}
		}
	}
	group[cur] = tc;
}

int main()
{
	scanf("%d", &tc);

	while(tc) {
		int i, n;
		cnt = 0;
		scanf("%d", &n);

		for(i=1; i<=n; i++) {
			scanf("%d", g+i);
		}

		for(i=1; i<=n; i++) {
			if(visited[i]!=tc)
				dfs(i);
		}
		printf("%d\n", n-cnt);
		tc--;
	}

	return 0;
}
