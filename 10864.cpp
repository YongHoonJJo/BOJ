#include <stdio.h>

int cnt[1001];

int main()
{
	int i, n, m;
	scanf("%d %d", &n, &m);
	
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		cnt[a]++;
		cnt[b]++;
	}

	for(i=1; i<=n; i++)
		printf("%d\n", cnt[i]);

	return 0;
}
