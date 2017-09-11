#include <stdio.h>

int a[1001];

int main()
{
	int i, n;
	int mod, t=0;
	scanf("%d", &n);

	mod = n;

	for(i=0; i<n; i++)
		scanf("%d", a+i);

	while(n > 1) {
		int gap = a[t];
		a[t] = 0;
		printf("%d ", t+1);
		n--;
		if(gap > 0) {
			while(gap--) {
				t++;
				t%=mod;
				if(!a[t]) gap++;
			}
		}
		else {
			while(gap++) {
				t--;
				if(t<0) t=mod-1;
				if(!a[t]) gap--;
			}
		}
	}

	for(i=0; i<mod; i++)
		if(a[i])
			printf("%d\n", i+1);

	return 0;
}
