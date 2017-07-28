#include <stdio.h>

int main()
{
	int i, j, n;
	int Max=0, maxI, maxJ;
	for(i=1; i<=9; i++) {
		for(j=1; j<=9; j++) {
			scanf("%d", &n);
			if(Max < n) {
				Max = n;
				maxI = i;
				maxJ = j;
			}
		}
	}
	printf("%d\n%d %d\n", Max, maxI, maxJ);			
	return 0;
}
