#include <stdio.h>

int a[1000001], idx[1000001], ck[1000001];
int n, ans;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int go(int k, int i)
{
	int ret=1;
	if(k == n) return 1;
	if(ck[k]) return 0;
	ck[k] = 1;
	if(idx[k+1] > i)
		ret += go(k+1, idx[k+1]);
	return ret;
}
int main()
{
	int i;
	scanf("%d", &n);
	
	for(i=1; i<=n; i++) { 
		scanf("%d", a+i);
		idx[a[i]] = i;
	}
	for(i=1; i<=n; i++) {
		ans = Max(ans, go(a[i], i));	
	}
	printf("%d\n", n-ans);
}
