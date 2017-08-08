#include <stdio.h>

int main()
{
	int d, k, i=5;
	int ans=0;
	scanf("%d", &d);

	while(i--) {
		scanf("%d", &k);
		if(d == k) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
