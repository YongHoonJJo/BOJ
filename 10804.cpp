#include <stdio.h>

int main()
{
	int i, c[21];

	for(i=0; i<21; i++)
		c[i] = i;

	i = 10;
	while(i--) {
		int a, b;
		scanf("%d%d", &a, &b);
		while(a < b) {
			int t = c[a];
			c[a] = c[b];
			c[b] = t;
			a++; b--;
		}
	}

	for(i=1; i<21; i++)
		printf("%d ", c[i]);
	puts("");

	return 0;
}
