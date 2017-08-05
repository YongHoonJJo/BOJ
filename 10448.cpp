#include <stdio.h>

int a[50];

int isTri(int n)
{	
	int i, j, k;
	for(i=1; i<50; i++)
		for(j=1; j<50; j++)
			for(k=1; k<50; k++)
				if(a[i]+a[j]+a[k]==n) 
					return 1;
	return 0;
}

int main()
{
	int i, n, k;
	scanf("%d", &n);

	for(i=1; i<50; i++)
		a[i] = a[i-1]+i;

	while(n--) {
		scanf("%d", &k);
		isTri(k) ? puts("1") : puts("0");
	}

	return 0;
}
