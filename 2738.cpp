#include <stdio.h>

int a[101][101];

int main()
{
	int i, j, k;
	int n, m;
	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++) 
		for(j=0; j<m; j++)
			scanf("%d", &a[i][j]);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &k);
			a[i][j] += k;
		}
	}

	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) 
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}
