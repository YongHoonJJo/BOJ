#include <stdio.h>

int a[101][101], b[101][101], c[101][101];

int main()
{
	int i, j, x;
	int n, m, k;
	scanf("%d%d", &n, &m);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d", &a[i][j]);

	scanf("%d%d", &m, &k);
	for(i=0; i<m; i++)
		for(j=0; j<k; j++)
			scanf("%d", &b[i][j]);

	for(i=0; i<n; i++) 
		for(j=0; j<k; j++) 
			for(x=0; x<m; x++) 
				c[i][j] += (a[i][x]*b[x][j]);

	for(i=0; i<n; i++) {
		for(j=0; j<k; j++) 
			printf("%d ", c[i][j]);
		puts("");
	}

	return 0;
}
