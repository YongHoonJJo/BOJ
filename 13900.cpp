#include <stdio.h>

int s[100001];

int main()
{
	int i, n, k;
	long long ans=0LL;
	scanf("%d%d", &n, s+1);

	for(i=2; i<=n; i++) {
		scanf("%d", &k);
		s[i] = s[i-1]+k;
		ans += 1LL*k*s[i-1];
	}

	printf("%lld\n", ans);
	return 0;
}
