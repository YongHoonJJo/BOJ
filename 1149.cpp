#include <stdio.h>

int rgb[1001][3], d[1001][3];

int min(int a, int b)
{
	return a > b ? b : a;
}

int go(int n, int color)
{
	int ret;
	if(n < 0) return 0; 
	if(d[n][color]) return d[n][color];	
	ret = go(n-1, (color+1)%3);
	ret = min(ret, go(n-1, (color+2)%3));	
	return d[n][color] = ret+rgb[n][color];
}

int main()
{
	int i, j, n, ans;
	scanf("%d", &n);

	for(i=0; i<n; i++) 
		for(j=0; j<3; j++) 
			scanf("%d", &rgb[i][j]);
	
	ans = go(n-1, 2);
	ans = min(ans, go(n-1, 1)); 
	ans = min(ans, go(n-1, 0)); 
	printf("%d\n", ans);
	return 0;
}
