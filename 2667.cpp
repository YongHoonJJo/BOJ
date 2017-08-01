#include <stdio.h>
#include <algorithm>

#define N 101
int n, cnt, a[N][N], s[N];

bool safe(int x, int y)
{
	return (0 <= x < n) && (0<= y < n);
}

bool cmp(int a, int b)
{
	return a < b;
}

void dfs(int x, int y, int k)
{
	int i, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
	a[x][y] = k;
	for(i=0; i<4; i++)
		if(safe(x+dx[i], y+dy[i]) && a[x+dx[i]][y+dy[i]]==1 )
			dfs(x+dx[i], y+dy[i], k);
}	

void solve(void)
{
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(a[i][j] == 1)
			{
				cnt++;
				dfs(i, j, cnt+1);
			}

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(a[i][j])
				s[a[i][j]-2]++;

	std::sort(s, s+cnt, cmp);
}

int main(void)
{
	int i, j;
	scanf("%d", &n);

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%1d", &a[i][j]);

	solve();

	printf("%d\n", cnt);
	for(i=0; i<cnt; i++)
		printf("%d\n", s[i]);

	return 0;
}
