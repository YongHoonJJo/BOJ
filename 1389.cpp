#include <stdio.h>
#define INF 1000000

int g[101][101];
int idx, ans = INF;

int main()
{
	int i, j, k, n, m;
	scanf("%d %d", &n, &m);

	for(i=0; i<=n; i++) {
		for(j=0; j<=n; j++)
			g[i][j] = INF;
		g[i][i] = 0;
	}

	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}

	for(k=1; k<=n; k++) 
		for(i=1; i<=n; i++) 
			for(j=1; j<=n; j++) 
				if(g[i][j] > g[i][k] + g[k][j]) 
					g[i][j] = g[i][k] + g[k][j];

	for(i=1; i<=n; i++) {
		int sum=0;
		for(j=1; j<=n; j++) {
			sum += g[i][j];
		}
		if(ans > sum) {
			ans = sum;
			idx = i;
		}
	}

	printf("%d\n", idx);
	return 0;
}
