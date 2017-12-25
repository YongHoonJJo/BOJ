#include <stdio.h>
#define INF	1000000000

int tg[100001][3];
int dp[100001][3];

int go(int n, int m)
{
	int a, b, c, d;
	if(m < 0 || m > 2) return INF;
	if(n == 0) {
		if(m == 0) return INF;
		if(m == 1) return tg[0][1];
		if(m == 2) return tg[0][1]+tg[0][2];
	}
	if(dp[n][m] != INF) return dp[n][m];

	a = go(n, m-1);
	b = go(n-1, m-1);
	c = go(n-1, m);
	d = go(n-1, m+1);

	a = a > b ? b : a;
	c = c > d ? d : c;

	a = a > c ? c : a;
	return dp[n][m] = a+tg[n][m];
}

int main()
{
	int i, n, k=1;
	while(1) {
		scanf("%d", &n);
		if(!n) break;

		for(i=0; i<n; i++) {
			scanf("%d %d %d", tg[i], tg[i]+1, tg[i]+2);
			dp[i][0] = dp[i][1] = dp[i][2] = INF;
		}

		printf("%d. %d\n", k, go(n-1, 1));
		k++;
	}
	return 0;
}
