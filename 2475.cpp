#include <stdio.h>

int main()
{
	int i=5, k, ans=0;
	
	while(i--) {
		scanf("%d", &k);
		ans += k*k;
	}
	printf("%d\n", ans%10);
	return 0;
}
