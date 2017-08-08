#include <stdio.h>

int x, pSum[5000];

int main()
{
	int i, j=1, k;
	scanf("%d", &x);
	
	for(i=1; i<5000; i++)
		pSum[i] = pSum[i-1]+i;
	
	i=1;
	while(pSum[i] < x) i++;

	k = i;
	x -= pSum[i-1];
	while(--x) {
		j++;
		i--;
	}

	if(k&1) printf("%d/%d\n", i, j);
	else printf("%d/%d\n", j, i);

	return 0;
}
