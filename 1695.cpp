#include <stdio.h>
#include <string.h>
#define INF	1000000000

int a[5001], d[5001][5001];

int Min(int a, int b)
{
	return a < b ? a : b;
}

int go(int s, int e)
{
	int i, ret=d[s][e];
	if(s >= e) return 0;
	if(ret != -1) return ret;

	ret = INF;
	if(a[s] == a[e]) 
		ret = Min(ret, go(s+1, e-1));
	else {
		ret = Min(ret, go(s, e-1)+1);
		ret = Min(ret, go(s+1, e)+1);
	}
	return d[s][e] = ret;
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for(i=0; i<n; i++) 
		scanf("%d", a+i);
	memset(d, -1, sizeof(d));
	printf("%d\n", go(0, n-1));
	return 0;
}
