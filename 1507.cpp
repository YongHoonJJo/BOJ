#include <stdio.h>

int g[21][21], del[21][21];

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int i, j, k, n;	
	int ans=0;
	scanf("%d", &n);

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &g[i][j]);

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			int minD = 10e9;
			for(k=0; k<n; k++) {
				if(i!=k && j!=k)
					minD = min(minD, g[i][k]+g[k][j]);
				if(minD < g[i][j]) {
					puts("-1");
					return 0;
				}
				if(minD == g[i][j])
					del[i][j] = 1;
			}
		}
	}

	for(i=0; i<n; i++) 
		for(j=i+1; j<n; j++)
			if(!del[i][j]) 
				ans += g[i][j]; 

	printf("%d\n", ans);
	return 0;
}
