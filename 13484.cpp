#include <stdio.h>

int main()
{
	int i, x, n, ans=0;
	int p[101], pSum=0;;
	scanf("%d%d", &x, &n);

	for(i=0; i<n; i++) {
		scanf("%d", p+i);
		pSum += p[i];
	}

	ans = x*(n+1)-pSum;
	printf("%d\n", ans);
	return 0;
}
