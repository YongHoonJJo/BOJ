#include <stdio.h>

int a[1000001];

int main()
{
	int i, n, fac=1;
	long long ans=0;
	scanf("%d", &n);

	for(i=0; i<n; i++) 
		scanf("%d", a+i);

	while(1) {
		int cnt=0, sum=0, zero=0;
		for(i=0; i<n; i++) {
			if(a[i]&1) cnt++;
			else zero++;
			a[i] >>= 1;
			sum += a[i];
		}
		if(cnt != n)
			ans += (1LL*fac*cnt*zero);
		fac <<= 1;
		if(!sum) break;
	}
	printf("%lld\n", ans);
	return 0;
}
