#include <stdio.h>
#include <string.h>

int n, m;
int g[501][501], d[501][501];
int dr[]={1, 0, -1, 0};
int dc[]={0, 1, 0, -1};

int safe(int r, int c)
{
	return (0 <= r && r < n) && (0 <= c && c < m);
}

int go(int r, int c)
{
	int i, ret=0;
	if(!r && !c) return 1;
	if(d[r][c] != -1) return d[r][c];

	for(i=0; i<4; i++) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if(safe(nr, nc) && g[nr][nc] > g[r][c]) 
			ret += go(nr, nc);
	}
	return d[r][c] = ret;	
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d", &g[i][j]);

	memset(d, -1, sizeof(d));
	printf("%d\n", go(n-1, m-1));

	return 0;
}
