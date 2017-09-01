#include <stdio.h>

int g[101][101];

int main()
{
	int i, j, k, n;
	scanf("%d", &n);

	for(i=0; i<n; i++)  
		for(j=0; j<n; j++) 
			scanf("%d", &g[i][j]);


	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(g[i][k] && g[k][j])
					g[i][j] = 1;

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++)
			printf("%d ", g[i][j]);
		puts("");
	}

	return 0;
}
