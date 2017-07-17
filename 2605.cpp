#include <stdio.h>

int main()
{
	int i, j, n;
	int no[101], std[101];
	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%d", no+i);

	std[0] = 1;
	for(i=1; i<n; i++) {
		for(j=i; j>i-no[i]; j--)
			std[j] = std[j-1];
		std[i-no[i]] = i+1;
	}

	for(i=0; i<n; i++)
		printf("%d ", std[i]);
	puts("");
	return 0;
}
