#include <stdio.h>

int W, L;

int main()
{
	int i, k, a[10];

	for(i=0; i<10; i++)
		scanf("%d", a+i);

	for(i=0; i<10; i++) {
		scanf("%d", &k);
		if(a[i] != k)
			a[i] > k ? W++ : L++;
	}

	if(W == L) puts("D");
	else W > L ? puts("A") : puts("B");

	return 0;
}
