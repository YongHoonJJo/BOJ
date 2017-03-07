#include <stdio.h>

int b[100001];

int main()
{
	int i, n, m, x, y;
	scanf("%d %d", &n, &m);

	for(i=1; i<=n; i++) {
		scanf("%d", &x);
		b[i] = b[i-1] + x;
	}

	while(m--) {
		scanf("%d %d", &x, &y);
		printf("%d\n", b[y]-b[x-1]);	
	}

	return 0;
}
