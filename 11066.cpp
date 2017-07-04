#include <stdio.h>
#include <string.h>

int file[501], d[501][501];
int pSum[501];

int min(int a, int b)
{
	return a > b ? b : a;
}

int go(int a, int b)
{
	int i, ret=0x7fffffff;
	if(a == b) return 0;
	if(d[a][b]) return d[a][b];

	for(i=a; i<b; i++)
		ret = min(ret, go(a, i)+go(i+1, b) + pSum[b]-pSum[a-1]);
	return d[a][b] = ret;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, n;
		scanf("%d", &n);
		
		memset(pSum, 0, sizeof(pSum));
		for(i=1; i<=n; i++) {
			scanf("%d", file+i);
			pSum[i] += (pSum[i-1]+file[i]);
		}

		memset(d, 0, sizeof(d));
		printf("%d\n", go(1, n));
	}

	return 0;
}
