#include <stdio.h>

int main()
{
	int i, j, n;
	scanf("%d", &n);

	for(i=0; i<n*2; i++) {
		for(j=0; j<n; j++)
			printf("%c", (i+j)&1 ? ' ' : '*');
		puts("");
	}
	return 0;
}
