#include <stdio.h>
#define INF	1000000000

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, m;
	int i, j, k;
	int dist[100][100];
	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++) 
		for(j=0; j<n; j++) 
			dist[i][j] = i==j ? 0 : INF;

	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dist[a-1][b-1] = min(dist[a-1][b-1], c);
	}

	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++)
			printf("%d ", dist[i][j]);
		puts("");
	}

	return 0;
}
