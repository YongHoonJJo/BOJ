#include <stdio.h>

int n, a[301], d[301];

int Max(int x, int y)
{
	return x > y ? x : y;
}	

int go(int k) 
{
	int x, y;
	if(d[k]) return d[k];
	if(k < 1) return 0;

	x = a[k-1] + go(k-3);
	y = go(k-2);

	return d[k] = Max(x, y) + a[k];
}

int main()
{
	int i;
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		scanf("%d ", a+i);

	d[1] = a[1];
	d[2] = a[1]+a[2];
	printf("%d\n", go(n));

	return 0;
}


