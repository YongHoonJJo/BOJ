#include <stdio.h>

int d[31];

int main()
{
	int i, j, n;
	scanf("%d", &n);

	d[0] = 1; d[2] = 3;
	if(!(n&1)) {
		for(i=4; i<=n; i+=2) {
			d[i] += 3*d[i-2];
			j = 4;
			while(i-j >= 0) {
				d[i] += (2*d[i-j]);
				j += 2;
			}
		}
	}
	printf("%d\n", d[n]);
	return 0;
}
