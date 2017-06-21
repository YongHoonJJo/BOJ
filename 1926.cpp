#include <stdio.h>

int r, c, cnt, tmp;
int g[501][501];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

int safe(int i, int j)
{
	return (0 <= i && i < r) && (0 <= j && j < c);
}

void dfs(int i, int j)
{
	int k;
	g[i][j] = 0;
	tmp++;

	for(k=0; k<4; k++) {
		int ni = i+dx[k];
		int nj = j+dy[k];
		if(safe(ni, nj) && g[ni][nj])
			dfs(ni, nj);
	}
}

int main()
{
	int i, j, ans=0;
	scanf("%d%d", &r, &c);		

	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
			scanf("%d", &g[i][j]);

	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			if(g[i][j]) {
				ans++;
				tmp = 0;
				dfs(i, j);
				if(cnt < tmp)
					cnt = tmp;
			}
		}
	}
	
	printf("%d\n%d\n", ans, cnt);
	return 0;
}
