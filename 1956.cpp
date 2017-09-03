#include <stdio.h>
#define INF 0x3f3f3f3f

int g[401][401];

int main()
{
	int v, e;
	int i, j, k;
	int ans = INF;
	scanf("%d%d", &v, &e);

	for(i=1; i<=v; i++) 
		for(j=1; j<=v; j++)
			g[i][j] = INF;

	while(e--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = c;
	}

	for(k=1; k<=v; k++)
		for(i=1; i<=v; i++)
			for(j=1; j<=v; j++)
				if(g[i][j] > g[i][k]+g[k][j])
					g[i][j] = g[i][k]+g[k][j];

	for(i=1; i<=v; i++)
		if(ans > g[i][i])
			ans = g[i][i];

	if(ans == INF) ans = -1;
	printf("%d\n", ans);
	return 0;
}
