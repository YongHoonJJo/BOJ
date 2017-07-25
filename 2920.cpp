#include <stdio.h>

int main()
{
	int i, asc, a[8];
	for(i=0; i<8; i++)
		scanf("%d", a+i);

	asc = a[0]<a[1];
	for(i=2; i<8; i++) {
		if((a[i-1]<a[i] && !asc) || (a[i-1]>a[i] && asc)) {
			puts("mixed");
			return 0;
		}
	}

	asc ? puts("ascending") : puts("descending");
	return 0;
}
