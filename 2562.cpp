#include <stdio.h>

int main()
{
	int i, k, idx, ans=0;
	for(i=1; i<=9; i++) {
		scanf("%d", &k);
		if(ans < k) {
			ans = k;
			idx = i;
		}
	}
	printf("%d\n%d\n", ans, idx);
	return 0;
}
