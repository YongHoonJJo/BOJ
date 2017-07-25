#include <stdio.h>
#include <string.h>

int a[2001], d[2001], e[2001];

int main()
{
	int i, j, n;	
	int ans=0;
	scanf("%d", &n);

	for(i=n; i>=1; i--) {
		scanf("%d", a+i);
	}

	for(i=1; i<=n; i++) {
		d[i] = e[i] = 1;
		for(j=1; j<=i; j++) {
			if(a[j] < a[i] && d[j]+1 > d[i])
				d[i] = d[j] + 1;
			if(a[j] > a[i] && e[j]+1 > e[i])
				e[i] = e[j] + 1;
		}
	}

	for(i=1; i<=n; i++) {
		if(ans < d[i]+e[i]-1)
			ans = d[i]+e[i]-1;
	}

	printf("%d\n", ans);
	return 0;
}
