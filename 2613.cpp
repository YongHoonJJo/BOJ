#include <stdio.h>

int a[301], d[301][301];
int pSum[301], cnt[301][301];

int max(int a, int b)
{
	return a > b ? a : b;
}

void count(int n, int m)
{
	if(m == 0) return ;
	count(n-cnt[n][m], m-1);
	printf("%d ", cnt[n][m]);
}

int go(int n, int m)
{
	int i, ret=0x7fffffff;
	if(d[n][m]) return d[n][m];
	if(m == 1) {
		cnt[n][m] = n;
		return d[n][m] = pSum[n];
	}
	for(i=n-1; i>=m-1; i--) {
		int tmp = max(pSum[n]-pSum[i], go(i, m-1));
		if(ret > tmp) {
			ret = tmp;
			cnt[n][m] = n - i;
		}
	}
	return d[n][m] = ret;
}

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);

	for(i=1; i<=n; i++) {
		scanf("%d", a+i); 
		pSum[i] = pSum[i-1]+a[i];
	}

	printf("%d\n", go(n, m));
	count(n, m);
	puts("");
	return 0;
}

