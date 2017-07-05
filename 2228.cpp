#include <stdio.h>

int a[101];
int d[101][101], ck[101][101];

int go(int n, int m)
{
	int k, ans, tmp=0, sum=0;	
	if(m == 0) return 0;
	if(n <= 0) return -1e9;
	if(ck[n][m]) return d[n][m];	
	ck[n][m] = 1;

	ans = go(n-1, m);
	for(k=n; k>=1; k--) {
		sum += a[k];
		tmp = go(k-2, m-1) + sum;
		if(ans < tmp) ans = tmp;
	}
	return d[n][m] = ans;
}

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);

	for(i=1; i<=n; i++) {
		scanf("%d", a+i);
	}
	printf("%d\n", go(n, m));	
	return 0;
}
