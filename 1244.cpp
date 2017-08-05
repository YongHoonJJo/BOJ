#include <stdio.h>

int main()
{
	int i, n, m, sw[101];
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		scanf("%d", sw+i);

	scanf("%d", &m);
	while(m--) {
		int s, k;
		scanf("%d%d", &s, &k);
		if(s == 1) {
			for(i=k; i<=n; i+=k)
				sw[i] = !sw[i];
		}
		else {
			i = 1;
			sw[k] = !sw[k];
			while(1) {
				if(k-i < 0 || k+i > n) break;
				if(sw[k-i] != sw[k+i]) break;
				sw[k-i] = !sw[k-i];
				sw[k+i] = !sw[k+i];
				i++;
			}
		}
	}
	for(i=1; i<=n; i++) {
		printf("%d ", sw[i]);
		if(i%20 == 0) puts("");
	}
	puts("");
	return 0;
}
