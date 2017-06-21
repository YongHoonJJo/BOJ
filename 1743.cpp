#include <stdio.h>

int n, m, k;
int g[101][101];
int ans, cnt;
int di[]={1, -1, 0, 0};
int dj[]={0, 0, 1, -1};

int safe(int i, int j)
{
	return (0 <= i && i < n) && (0 <= j && j < m); 
}

void dfs(int i, int j)
{
	int k;
	g[i][j] = 0;
	cnt++;

	for(k=0; k<4; k++) {
		int ni = i+di[k];
		int nj = j+dj[k];
		if(safe(ni, nj) && g[ni][nj])
			dfs(ni, nj);
	}
}

int main()
{
	int i, j;
	scanf("%d%d%d", &n, &m, &k);

	while(k--) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a-1][b-1] = 1;
	}

	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(g[i][j]) {
				cnt=0;
				dfs(i, j);
				if(ans < cnt)
					ans = cnt;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
