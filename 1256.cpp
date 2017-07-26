#include <stdio.h>
#define INF 1000000000

int d[201][101];

int Min(int a, int b)
{
	return a < b ? a : b;
}

void go(int n, int m, int k)
{
	if(n+m == 0) return ;
	if(d[n+m-1][m] >= k) {
		printf("%c", 'a');
		go(n-1, m, k);
	}
	else {
		printf("%c", 'z');
		go(n, m-1, k-d[n+m-1][m]);
	}
}

int main()
{
	int n, m, k;
	for(k=0; k<=200; k++) {
		d[k][0] = 1;
		for(n=1; n<=k; n++) 
			d[k][n] = Min(d[k-1][n-1]+d[k-1][n], INF);
	}

	scanf("%d%d%d", &n, &m, &k);
	if(d[n+m][m] < k) puts("-1");
	else go(n, m, k);
	return 0;
}
