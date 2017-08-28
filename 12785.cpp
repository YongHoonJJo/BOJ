#include <stdio.h>
#define MOD 1000007

int d[201][201];

int go(int x, int y, int r, int c)
{
	if(r < x || c < y) return 0;
	if(r == x && c == y) return 1;
	if(d[r][c]) return d[r][c];
	return d[r][c] = (go(x, y, r-1, c)+go(x, y, r, c-1))%MOD;
}

int main()
{
	int w, h, x, y;
	scanf("%d%d%d%d", &w, &h, &x, &y);
	printf("%lld\n", (1LL*go(1, 1, x, y)*go(x, y, w, h))%MOD);
	return 0;
}
