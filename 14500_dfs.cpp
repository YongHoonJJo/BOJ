#include <stdio.h>
#define INF	-100000000

int n, m, ans;
int g[501][501], visited[501][501];
int dr[]={1, 0, -1, 0};
int dc[]={0, 1, 0, -1};

int safe(int r, int c) { return (0 <= r && r < n) && (0 <= c && c < m); }

void dfs(int curR, int curC, int sum, int cnt)
{
	int k;
	if(cnt == 3) {
		if(ans < sum) ans = sum;
		return ;
	}

	visited[curR][curC] = 1;
	for(k=0; k<4; k++) {
		int nR = curR+dr[k];
		int nC = curC+dc[k];
		if(safe(nR, nC) && !visited[nR][nC]) {
			dfs(nR, nC, sum+g[nR][nC], cnt+1);
		}
	}
	visited[curR][curC] = 0;
}

int main()
{
	int i, j, k;
	scanf("%d%d", &n, &m);
		
	for(i=0; i<n; i++) 
		for(j=0; j<m; j++) 
			scanf("%d", &g[i][j]);
	
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			int Min=1000, sum=g[i][j];
			dfs(i, j, g[i][j], 0);

			for(k=0; k<4; k++) {
				int nR = i+dr[k];
				int nC = j+dc[k];
				int tmp = (safe(nR, nC) ? g[nR][nC] : INF);
				if(Min > tmp) Min = tmp;
				sum += tmp;
			}
			if(ans < sum-Min) ans = sum-Min;
		}
	}

	printf("%d\n", ans);
	return 0;
}
