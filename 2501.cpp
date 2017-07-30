#include <stdio.h>

int main()
{
	int i, n, k, ans=0;
	
	scanf("%d%d", &n, &k);
	for(i=1; i<=n; i++) {
		if(n%i == 0) {
			k--;
			if(!k) ans = i;
		}	
	}
	printf("%d\n", ans);
	return 0;
}
