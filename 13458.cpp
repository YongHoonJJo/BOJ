#include <stdio.h>

int n, a[1000001];
int b, c;
long long ans;

int main()
{
	int i;
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", a+i);
	scanf("%d%d", &b, &c);
	
	ans = n;
	for(i=0; i<n; i++)
		a[i] -= b;
	
	for(i=0; i<n; i++) {
		if(a[i] > 0) {
			ans += a[i]/c;
			if(a[i]%c) ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
