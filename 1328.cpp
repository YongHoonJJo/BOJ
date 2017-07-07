#include <stdio.h>
#include <string.h>
#define MOD	1000000007

long long d[101][101][101];

long long go(int n, int L, int R)
{
	if(n < 1 || L == 0 || R == 0) return 0;
	if(n == 1 && L == 1 && R == 1) return 1;
	if(d[n][L][R]!=-1) return d[n][L][R];

	return d[n][L][R] = (go(n-1, L-1, R)+go(n-1, L, R-1)+go(n-1, L, R)*(n-2))%MOD;
}


int main()
{
	int n, L, R;
	scanf("%d%d%d", &n, &L, &R);

	memset(d, -1, sizeof(d)); // 없으면 시간초과
	printf("%lld\n", go(n, L, R));

	return 0;
}
