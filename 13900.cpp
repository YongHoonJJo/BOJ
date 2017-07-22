#include <stdio.h>

int a[100001], pSum[100001];

int main()
{
	int i, n;
	long long ans=0LL;
	scanf("%d", &n);

	for(i=1; i<=n; i++) {
		scanf("%d", a+i);
		pSum[i] = pSum[i-1]+a[i];
	}

	for(i=n; i>1; i--) 
		ans += 1LL*a[i]*pSum[i-1];

	printf("%lld\n", ans);
	return 0;
}
