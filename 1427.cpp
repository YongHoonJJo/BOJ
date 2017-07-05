#include <stdio.h>

int main()
{
	int i, n, cnt[10]={0};		
	scanf("%d", &n);
	
	while(n) {
		cnt[n%10]++;
		n/=10;
	}

	for(i=9; i>=0; i--) {
		int j;
		for(j=0; j<cnt[i]; j++) {
			printf("%d", i);
		}
	}
	puts("");
	return 0;
}
