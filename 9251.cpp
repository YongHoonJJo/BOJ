#include <stdio.h>
#include <string.h>

// d[i][j] : s[1]...s[i]와 t[1]...t[j]에 대한 LCS의 길이
int d[1001][1001]; 
char s[1001], t[1001];

int go(int n, int m)
{
	int ret;
	if(n < 0 || m < 0) return 0;
	if(d[n][m] != -1) return d[n][m];

	if(s[n] == t[m])
		ret = go(n-1, m-1)+1;
	else {
		int a = go(n-1, m);
		int b = go(n, m-1);
		ret = a > b ? a : b;
	}
	return d[n][m] = ret;
}

int main()
{
	int n, m;
	scanf("%s%s", s, t);

	memset(d, -1, sizeof(d));

	n = strlen(s);
	m = strlen(t);
	printf("%d\n", go(n-1, m-1));

	return 0;
}
