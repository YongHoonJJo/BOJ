#include <stdio.h>
#include <string.h>

char s[101], t[101], r[101];
int d[101][101][101];

int go(int n, int m, int k)
{
	int ret;

	if(n<0 || m<0 || k<0) return 0;
	if(d[n][m][k] != -1) return d[n][m][k];

	if(s[n]==t[m] && t[m]==r[k]) {
		ret = go(n-1, m-1, k-1)+1;
	}
	else {
		int a = go(n-1, m, k);
		int b = go(n, m-1, k);
		int c = go(n, m, k-1);
		if(a >= b && a >= c) 
			ret = a;
		else 
			ret = (b >= a && b >= c) ? b : c;
	}
	return d[n][m][k] = ret;
}

int main()
{
	int n, m, k;
	scanf("%s%s%s", s, t, r);

	n = strlen(s);
	m = strlen(t);
	k = strlen(r);
	memset(d, -1, sizeof(d));
	printf("%d\n", go(n-1, m-1, k-1));
	return 0;
}
