#include <stdio.h>

int g[101][101];
long long d[101][101];

long long go(int i, int j)
{
	int k;
	if(i<1 || j<1) return 0;
	if(i==1 && j==1) return 1;
	if(d[i][j]) return d[i][j];

	for(k=0; k<j; k++)
		if(k+g[i][k] == j)
			d[i][j] += go(i, k);

	for(k=0; k<i; k++)
		if(k+g[k][j] == i)
			d[i][j] += go(k, j);

	return d[i][j];
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &g[i][j]);

	printf("%lld\n", go(n, n));;

	return 0;
}
